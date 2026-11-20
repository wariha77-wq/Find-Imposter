#include "Case.h"
#include "Interrogation.h"

int main() {
    Case c("CASE 001 - THE MIDNIGHT HEIST",
           "Blackwood Manor. During a power outage, the Star of Midnight sapphire "
           "vanished from its display cabinet. Who is the impostor?");

    // ---- Suspects (text copied from the GUI) ----
    c.addSuspect(Suspect(1, "Victor Blackwood", "The Owner", 58,
        "The manor's wealthy owner. Rumours suggest he has been facing serious financial "
        "difficulties and recently increased the sapphire's insurance coverage.",
        "Says he was in the east hall during the outage."));
    c.addSuspect(Suspect(2, "Adrian Cole", "The Assistant", 31,
        "Victor's personal assistant. He knows the manor's layout and manages several "
        "household records. He claims he remained in the music room during the outage.",
        "Claims he remained in the music room during the outage."));
    c.addSuspect(Suspect(3, "Nina Hart", "The Journalist", 27,
        "An investigative journalist invited to the manor. She was seen taking photographs "
        "near the gallery and has been investigating Victor's business dealings.",
        "Says she was near the west corridor checking her photographs."));
    c.addSuspect(Suspect(4, "Felix Morgan", "The Magician", 42,
        "A stage magician and former friend of Victor. He owns velvet performance pouches "
        "and was recently refused sponsorship for his new show.",
        "Says he was in the drawing room with two other guests."));

    // The real culprit (1=Victor 2=Adrian 3=Nina 4=Felix)
    c.setCulprit(2);

    // ---- Locations ----
    c.addLocation(Location(1, "Gallery", "The sapphire's display chamber. The silence feels deliberate."));
    c.addLocation(Location(2, "Study", "Victor's private study. A desk drawer and an open notebook catch your eye."));
    c.addLocation(Location(3, "Music room", "A grand piano and shelves of sheet music. Nothing seems out of place."));
    c.addLocation(Location(4, "West hallway", "A long corridor leading toward the gallery."));

    // ---- Clues: (id, title, description, location, points-to-suspect) ----
    // IDs, titles and wording are the same as the GUI.
    c.addClue(Clue(1, "The Missing Spare Key",
        "The spare cabinet key was reported missing three days before the party.", "Study", 2));
    c.addClue(Clue(2, "The Undamaged Lock",
        "The display cabinet's lock shows no signs of forced entry.", "Gallery", 0));
    c.addClue(Clue(3, "Blue Fibres",
        "Tiny blue fibres matching the display's velvet lining were found on a jacket.", "Gallery", 2));
    c.addClue(Clue(4, "The Floor Plan",
        "A detailed sketch of the manor's private rooms was found in a notebook.", "Study", 2));
    c.addClue(Clue(5, "Nina's Photograph",
        "A photograph timestamped 9:53 PM shows the display already empty.", "West hallway", 0));

    c.addValidLink(1, 2);   // missing spare key + undamaged lock
    c.addValidLink(1, 4);   // missing spare key + floor plan (planning)
    c.addValidLink(2, 3);   // undamaged lock + blue fibres (the cabinet)
 c.addValidLink(3, 5);   // blue fibres + Nina's photograph

    // ---- Interrogations (answers copied from the GUI) ----
    // Last number = clue that contradicts the answer (0 = none)
    Interrogation victor(c.findSuspect(1));
    victor.addQA("What happened during the outage?",
        "I was in the east hall. The lights went out for perhaps a minute. "
        "I heard a noise from the gallery, but I assumed it was one of the guests.", 0);
    victor.addQA("Why was the insurance increased?",
        "The sapphire's value has risen considerably. Any responsible owner would protect such an asset.", 0);
    victor.addQA("Who had access to the cabinet?",
        "The display was locked. I kept the main key. A spare key may have gone missing, "
        "but I only discovered that recently.", 1);

    Interrogation adrian(c.findSuspect(2));
    adrian.addQA("Where were you during the outage?",
        "In the music room, exactly where I had been before. I didn't go near the gallery that evening.", 3);
    adrian.addQA("Do you know the manor's layout?",
        "Only the usual staff areas. I have no reason to study the private rooms.", 4);
    adrian.addQA("Did you notice anything unusual?",
        "No. The lights returned quickly, and everyone seemed confused.", 0);

    Interrogation nina(c.findSuspect(3));
    nina.addQA("Why were you taking photographs?",
        "I'm writing a profile on Victor. The manor is part of the story, and the gallery was open to guests.", 0);
    nina.addQA("Where were you at 10 PM?",
        "Near the west corridor. I was checking the photographs on my camera.", 0);
    nina.addQA("Did you see the cabinet?",
        "I saw it earlier. I didn't touch it. I have no interest in stealing jewellery.", 0);

    Interrogation felix(c.findSuspect(4));
    felix.addQA("Why were you invited?",
        "Victor and I go back years. We disagree, but an invitation is an invitation.", 0);
    felix.addQA("Could you open a display lock?",
        "I'm a magician, detective, not a burglar. My tricks are performed on a stage.", 0);
    felix.addQA("Where were you during the outage?",
        "In the drawing room with two other guests. They can confirm that.", 0);

    // ================= DEMO RUN =================
    c.displayIntro();
    c.displaySuspects();

    cout << "\n\n=== EXPLORE: GALLERY ===";
    c.investigateLocation(1);
    c.discoverClue(2);
    c.discoverClue(3);

    cout << "\n\n=== INTERROGATE ===";
    adrian.displayQuestions();
    adrian.ask(1);
    adrian.ask(2);
    felix.ask(3);

    cout << "\n\n=== MORE EXPLORING ===";
    c.investigateLocation(2);  c.discoverClue(1);  c.discoverClue(4);
    c.investigateLocation(4);  c.discoverClue(5);

    cout << "\n\n=== CONTRADICTION CHECKS ===";
    adrian.checkContradictions(c);
    felix.checkContradictions(c);

    cout << "\n\n=== EVIDENCE WALL ===";
    c.connectClues(3, 4);   // wrong link on purpose
    c.connectClues(1, 2);   // correct link
    c.displayEvidenceBoard();

    cout << "\n\n=== ACCUSATION ===";
    c.accuse(2, 3);

    cout << "\nFinal Score: " << c.getScore() << "/100" << endl;
    return 0;
}
