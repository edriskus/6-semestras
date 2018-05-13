# Programų kūrimo procesas

## Įvadas į programų kūrimo procesą

- **PKP** - Sukurti reikiamą per nustatytą laiką telpant į sutartą biudžetą įrangą.
- Proceso pabaiga – ne laikas ir biudžetas, o tada, kada sprendimas yra išleidžiamas (angl. **release**)
- **Big Bang** (ėjimas į tamsą) sprendimo metodas - daug darbo ne iki galo suvokiant kas turi būti sukurta ir bendraujant su užsakovu tik pradžioje ir pabaigoje darbų.
- Užsakovas niekada iki galo nežino koks turi būti galutinis sprendimas
- **Iteracinis kelias:**
  - Užsakovas nuolat turi dalyvauti kūrimo procese
  - Visada klausk ką užsakovas vienu ar kitu atveju norėjo pasakyti,
  - Visada klausk ir prašyk pateikti daugiau detalių,
  - Visada klausk, kaip užsakovas įsivaizduoja būsimą programinį įgyvendinimą.
- Iteracijų panaudojimas užtikrina rezultato pasiekimą kuris tenkina užsakovą.
- **Waterfall** vs **Iterative**:
  - Reikiamos pastangos: 10 vs 1 (skaičiuojant asmens darbo val. per mėn.)
  - Greitis: 1 vs 7 (skaičiuojant per fiksuotą laiko tarpą)
  - Užsakovo pasitenkinimas (stakeholder): Menkas vs puikus
  - **Tačiau:** iteracinis ne visur veikia
- **Cynefin framework** offers a "sense of place" from which to analyse behaviour and make decisions
  - **Chaotic** (chaotiškas) - iš karto veikite, po to tikrinkite ar situacija aiškėja, stabilizuojasi ir ar galima pereiti į „Sudėtingas“ sritį.
    - Agile **nėra laiko** - Esama krizinėje situacijoje, tad privalu staigiai reaguoti siekiu sumažinti galimą neigiamą įtaką
  - **Complex** (sudėtingas) - tirkite problemą, patikrinkite sprendimą, jį pritaikykite
    - Agile požiūris **pakankamai gerai tinka**. Tyrimo pagrindu gautos žinios vertinamos ir pritaikomos
  - **Complicated** (painus) - Įvertinkite situaciją, keletą galimybių, remkitės gerąja patirtimi.
    - Agile tipo procesas **nėra pats geriausias** pasirinkimas. Egzistuoja keletas gerų sprendinių tačiau šiems „atrasti“ reikia ekspertų konsultacijos - neefektyvu bandyti rasti sprendimą patiems.
  - **Simple / Obvious** (paprastas) - Aiškus sąryšis tarp pasekmės ir priežasties, procesas aiškus ir deterministinis
    - Agile tipo procesas **nėra pats geriausias** pasirinkimas. Viskas ir taip aišku
  - **DISORDER** (betvarkė) - nėra aišku, kurios sritys veikia. Vienintelis būdas – problemą dekomponuoti į mažesnes ir kiekvieną jų priskirti likusioms 4 sritims.

## Naudotojų istorijos

- Planu grindžiamas (**nuoseklus**) NP:
  - Reikalavimai iš anksto aprašyti,
  - Nekintantys,
  - Nepriklausomi (moduliniai).
  - PĮ kūrėjams patiekiama kaip išsamus, iš anksto detaliai suplanuotas ir dokumentuotas PĮ veikimas
  - Pasikeitus reikalavimas, taikomas formalus procesas pakeitimams užtikrinti
- **Iteratyvaus** proceso IP:
  - Kyla proceso metu,
  - Nuolat diskutuojami,
  - Savalaikiai (JIT Just in time), tik pakankami (Just Enough) funkcionalumui suprogramuoti
  - Reikalavimai formuluojami pasiliekant laisvę juos keisti.
- **PBI** (product backlog items) yra tai ką reikia sukurti. PBI gali būti:
  - UC (use case)
  - NS (**user story**) ar pan
- **NS** yra skirta būsimo produkto, kuriančio pridėtinę vertę (benraja prasme) savybėms aprašyti:
  - NS turi suvokti tiek inžinieriai, tiek užsakovai
  - NS turi sudaryti pagrindą diskusijoms kilti
  - NS gali būti pateikiamos skirtingu detalumo ir turi būti lengvai tikslinamos
- NS yra grindžiamos **3C** (iš čia Tello, Glip, Slack ar pan.):
  - **Card** (kortelės, suvokimas). Tipiniu atveju kortelės turinys turi nusakyti: `Kaip <naudotojas> aš <kažko siekiu sistemos pagalba> tam, kad <kažką galėčiau gauti>`
    - Reikalavimo pavadinimą;
    - Naudotojo tipą/rolę;
    - Tikslą t. y. ką naudotojas nori pasiekti/atlikti;
    - Atsakyti, kodėl naudotojas siekia užsibrėžto tikslo.
  - **Conversation** (diskusijos) - NS yra „pažadas“, jog vyks diskusija
  - **Confirmation** (pasitenkinimo matai) - Kiekviena NS privalo nusakyti pasitenkinimo kriterijus
- **NS detalumas:**
  - **Epic** – leidžia suvokti „big-picture“
    - Epic – nusako „Lord of the Rings“ lygio siužetą
    - Epic niekada nenuleidžiamas į programavimo lygį
    - Jų pagrindu kuriamos smulkesnės istorijos – savaitinės
  - Savaitinės istorijos dar gali būti vadinamos požymiais (angl. **features**), kol kas nėra tinkamos įgyvendinti.
  - Istorijos, kurios matuojamos dienomis ir paprastai, perduodamos programuotojams įgyvendinti
    - Įsivertinamos valandomis/darbo dienomis
  - Kai kas istorijas apjungia bendra Tema
- **NS kokybė:**
  - Independent - Istorijos turi būti nepriklausomos, kuo mažiau susietos su kitomis
  - Negiotiable - Istorijos nėra pasirašytas kontraktas, jos turi būti aptariamos ir svarstomos
  - Valuable - Kiekviena istorija turi teikti tam tikrą naudą.
  - Estimatable - ...
  - Small - Istorijos dydis priklauso nuo iteracijos dydžio:
  - Testable - Ne visos istorijos turi būti testuojamos - Epic (jų pagrindu niekas kodo nerašo)
- **Nefunkciniai reikalavimai**: Sistemos lygio ribojimai apsprendžiantys projektavimo ir testavimo etapus ir turintys šiek tiek kitokią formuluotę
- **Žinių įgijimas** - Prototype, proof of concept, study, spike.
- **Istorijų surinkimas:** - įtraukti naudotoją į komandą, diskutuojant kas turi būti sukurta ir vertinant tai, kas jau yra sukurta:
  - Rolėmis grindžiamas surinkimas (NS Workshop) - diskusija `Aš kaip <koks?> sistemos naudotojas noriu, kad <kažkas> ...`
  - Istorijų žemėlapiai (Story Mapping) -  Išdėstymas sekomis leidžia lengviau pastebėti trūkstamas istorijas.

## Istorijų žurnalas

- PB - Product backlog - prioritetizuotas naudotojų istorijų sąrašas; koks ir kokia tvarka funkcionalumas turi būti įgyvendinamas
- Įrašų tipai:
  - **Feature** (Savybė):
    - Kaip klientus aptarnaujantis asmuo noriu turėti galimybę suteikti aptarnavimo užklausai numerį, tam kad galėčiau valdyti užklausą ir su ja susijusius duomenis.
  - **Change** (Pakeitimas):
    - Kaip klientus aptarnaujantis asmuo norėčiau, kad paieškos rezultatai būtų surūšiuoti pagal kliento pavardę, bet ne užklausos numerį
  - **Defect** (Defektas):
    - Ištaisyti defektą numeriu #157 (kažkokioje sistemoje), tam, kad paieškoje naudojami specialieji simboliai „nenulaužtų“ sistemos darbo.
  - **Technical work** (technologinis sprendimas):
    - Migruoti į paskutiniąją Oracle RDBMS versiją.
  - **Knowledge acquisition** (žinių gavyba):
    - Įgyvendinti POC palyginant dvi architektūras ir paleisti 3 testus siekiu išsiaiškinti kuri iš jų yra tinkamiausia.
- **DEEP**:
  - Detailed appropriately: Fiksuotu laiko momentu, PB įrašai bus detalizuoti skirtingai: bus skirtinguose abstrakcijos lygiuose (Epic->Task)
  - Emergent: Vykdant programinės įrangos kūrimo arba palaikymo darbus PB niekada nėra išbaigtas ar nekintantis; Kaip tik priešingai, - nuolat atnaujinamas atsižvelgiant į bet kokią ekonominę naudą, kuri kinta nuolatos
  - Estimated: Kiekvienas įrašas žurnale turi turėti įvertį nurodantį reikalingas pastangas darbui atlikti
  - Prioritized - Tipiniu atveju prioritetai suteikiami tiems įrašams kurie numatyti keliems artimiausiems sprintams / iteracijoms
- **Grooming**:
  - Proaktyvus veiklų valdymas, organizavimas, administravimas ir kt.
  - Dalyvauja visi, tačiau sprendžia product owner / lead / stakeholder
  - Tipiniu atveju grooming veiklos sudaro apie **10 proc.** kiekvienos iteracijos / sprinto laiko.
  - Įrašai **įvertinami**, **detalizuojami** ir **prioritetizuojami** atsižvelgiant į esamus išteklius ir technologinius ribojimus.
- **PB grooming** tikslas tinkamai paruošti istorijas sprintui:
  - Kuriama **pridėtinė vertė** yra aiškiai aprašyta
  - **Detalės yra suvoktos** ir komanda gali aiškiai įsivertinti kiek truks istorijos įgyvendinimas
  - Visos priklausomybės yra aiškios, **nėra** jokių kitų **išorinių priklausomybių** kurios trukdytų įgyvendinimui
  - Komanda **turi** sprinto reikalaujamą **kompetenciją**
  - Visa iteracija yra įvertinta, istorijos pakankamai mažos ir **gali būti įgyvendintos vieno sprinto metu**
  - **Confirmation** kriterijai yra aiškūs ir testuotini
  - **Performance** kriterijai yra aiškūs ir testuotini
  - Komanda suvokia kaip bus **demonstruojama** versija sprinto pabaigoje
- Siekiu užtikrinti savalaikį ir tinkamą srautą PB kuriamas darbų srautas turi būti nagrinėjamas šiais aspektais:
  - **Release srautas**. PBI skirstomos į 2-3 dalis:
    - Turi būti
    - Pageidautina (Istorijos keliaus į 2 release arba bus įgyvendintos 1-ame)
    - Tikrai nebus

## Naudotojų istorijų vertinimas ir darbų atlikimo greitis

- something
