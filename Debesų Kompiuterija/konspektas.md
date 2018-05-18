# Debesų kompiuterija

## Debesų kompiuterijos pagrindai

- Debesų kompiuterija gauna savo vardą kaip interneto **metafora**. Paprastai, internetas tinklo diagramose žymimas kaip debesis.
- Debesų kompiuterija leidžia sumažinti išlaidas ir, dar svarbiau, leidžia IT departamentui didžiausią dėmesį skirti strateginiams projektams, o ne duomenų centro priežiūrai.
- **Trūkumai**
  - Ryšio problemos
  - Gedimai, nepriklausantys nuo vartotojo
  - Programų suderinamumas
- Topologijos prasme, debesų kompiuterijos sprendimai yra sudaryti iš kelių elementų:
  - klientai (įrenginiai client)
  - duomenų centras
  - paskirstyti serveriai
- **Terminaliniai klientai** yra kompiuteriai, kurie neturi kietųjų diskų, o tik atvaizduoja iš serverio gaunamą informacija, leisdami serveriui atlikti visus skaičiavimus:
  - **Mažesnės išlaidos aparatūrai**. Terminaliniai klientai yra pigesni nei paprasti kompiuteriai, nes juose nėra kai kurių dalių. Jie taip pat ilgiau tarnauja.
  - **Mažesnės IT išlaidos**. Terminaliniai klientai yra valdomi serveryje ir yra mažesnė klaidų ir gedimų tikimybė.
  - **Saugumas**. Kadangi tvarkymas vyksta serveryje ir nėra kietojo disko, yra mažesnė tikimybė, kad kenkėjiškos programos užplūs įrenginį. Be to, kadangi terminaliniai klientai neveikia be serverio, yra mažesnė tikimybė, kad juos pavogtas.
  - **Duomenų saugumas**. Kadangi duomenys yra saugomi serveryje, yra mažesnė tikimybė prarasti duomenis, jei kliento kompiuteris yra sugadinamas arba pavogiamas.
  - **Mažesnis energijos vartojimas**. Terminaliniai klientai sunaudoja mažiau energijos nei įprastiniai kompiuteriai. Tai reiškia, kad reikės mažiau mokėti už elektrą ir už patalpų oro kondicionavimą.
  - **Lengva remontui ar pakeisti**. Jei terminalinis klientas sugenda, ji lengva pakeisti. Yra tiesiog pakeičiamas terminalas ir vartotojo gaunama lygiai tokia pati vartotojo aplinka, kuri buvo iki gedimo.
  - **Mažiau triukšmo**. Neturėdamas kietojo disko, bei kai kurių kitų dalių, terminalinis klientas mažiau kaista, tuomet silpnesni ir tyliau veikiantys ventiliatoriai gali būti naudojami aušinimui.
- **Tinklynai (Grid)** dažnai painiojami su debesų kompiuterija, tačiau jie yra gana skirtingi. Tinklynai taiko daugybės kompiuterių išteklius sprendžiant vieną problemą. Tai paprastai daroma sprendžiant įvairius mokslinius arba techninius uždavinius.
- **Virtualizacija** yra technologija, kuri leidžia vieną pilnai įdiegtą serverį paleisti kitame serveryje. Rezultatas yra sistema, kurioje visa programinė įranga veikianti serveryje yra talpinama virtualioje mašinoje.
- Nuo 2005, kai atsirado AMD Virtualization (AMD-V) ir Intel Virtualization Technology (IVT) virtualizacija tapo žymiai lengviau įgyvendinama.
- **Paravirtualizacija** leidžia kelias operacines sistemas paleisti ant vieno fizinio įrenginio tuo pačiu efektyviau naudojant sistemos išteklius, pavyzdžiui, procesorius ir atmintį.

---

- **Services** - Terminas paslaugos debesų kompiuterijoje reiškia galimybę naudoti atskirus daugkartinio naudojimo komponentus visame tiekėjo tinkle. Tai dažniausiai yra vadinama „kaip paslauga“.
- Programinė įranga kaip paslauga (**SaaS**) yra modelis, kuriame programa yra patalpinta kaip paslauga
  - Pvz.:
    - Klientų išteklių valdymo (Customer resource management - CRM)
    - Vaizdo konferencijos
    - IT paslaugų valdymas
    - Apskaita
    - Interneto analitika (Web Analytics)
    - Interneto turinio valdymas (Web content management)
  - Privalumai:
    - Naturalus interneto (World Wide Web) naudojimas.
    - Mažiau darbuotojų.
    - Pritaikomumas.
    - Geresnės pardavimo galimybės.
    - Interneto patikimumas.
    - Saugumas.
    - Didesnis pralaidumas.
  - Trūkumai:
    - Ribota konfigūracija
    - Prisirišimas prie tiekėjo
    - Vis tiek mokama (lyginant su Open Source)
- Platforma kaip paslauga (Platform as a Service - **PaaS**) yra kitas programinės įrangos teikimo modelis. PaaS tiekia visus išteklius, reikalingus kurti programas ir paslaugas visiškai tiesiog internete, nereikia atsisiųsti ar įdiegti programinę įrangą.
  - **Priedų kūrimo priemonės**. Šios priemonės leidžia pritaikyti esamus SaaS sprendimus prie vartotojų poreikių. Dažnai PaaS kūrėjai ir naudotojai privalo įsigyti abonementus ir atitinkamai SaaS paslaugai.
  - **Autonominės aplinkos**. Šios aplinkos nereikalauja licencijavimo, techninės arba finansinės priklausomybės bei konkrečių SaaS naudojimo ir gali būti taikomos naujų paslaugų kūrimui.
  - **Paslaugų teikimo aplinkos**. Šiose aplinkose teikiama talpinimo paslauga. Tokios aplinkos neturi paslaugos kūrimo, derinimo bei testavimo galimybių.
- Techninė įranga kaip paslauga (Hardware as a Service - **HaaS**) yra dar viena debesų kompiuterijos paslaugų rūšis.
  - SaaS ir PaaS teikia klientams programinę įrangą. HaaS tiesiog siūlo įrangos, kurią klientas gali naudoti taip, kaip jis nori, nuomą.
  - HaaS dalys:
    - **Paslaugų lygio sutartis**. Tai susitarimas tarp paslaugų teikėjo ir kliento, užtikrinantis tam tikro lygio sistemos produktyvumą.
    - **Kompiuterinė įranga**. Tai komponentai, kurių ištekliai bus išnuomoti. Paslaugų teikėjai dažnai naudoja grid technologijas užtikrinant plėtimo galimybes (scalability).
    - **Tinklas**. Tai ugniasienės, maršrutizatoriai, apkrovos optimizavimo įranga ir taip toliau.
    - **Interneto ryšys**. Internetas leidžia klientams pasiekti įrangą iš savo organizacijos.
    - **Platformos Virtualizacija**. Tai leidžia klientams paleisti tokias virtualias mašinas, kokias jie nori.
    - **Atsiskaitymas už panaudotus pajėgumus**. Paprastai klientai moka tik už tuos sistemos išteklius, kuriuos jie realiai naudoja.
- Dar viena paslauga, kurią siūlo debesų kompiuterija yra Duomenų bazė kaip paslauga (Database as a Service - **DaaS**). Pagrindinė DaaS idėja yra eliminuoti sudėtingumą ir kainą paleidžiant ir prižiūrint nuosavą duomenų bazę.

## Kada galima naudoti Debesų Kompiuteriją

- Apsisprendimas naudoti ar nenaudoti debesų kompiuterijos paslaugas priklauso nuo daugelio veiksnių, įskaitant:
  - Kainos / naudos santykis
  - Paslaugos teikimo greitis
  - Kokius resursus reikia naudoti
  - Ar turimi duomenys turi būti specifiškai saugomi
  - Organizacijos verslo ir IT struktūra
- Nereikia įsivaizduoti, kad debesų kompiuterija yra tinkama visiems gyvenimo atvejams. Yra daug atvejų, kai debesų kompiuterija gali būti **netinkama**:
  - Dirbant su duomenimis, apsaugotais įstatymo
  - Vyriausybė (FTP) turi teisę pasiekti duomenis debesyje
  - Geopolitiniai klausimai (Kanados duomenys negali gulėti JAV serveriuose)
  - Jei turite programą, kuri reikalauja specialios techninės įrangos, mikroschemų arba tvarkyklių, debesų sprendimai gali būti netinkami.
  - Jei reikia detaliai kontroliuoti atmintį, procesoriaus, kietojo disko arba kitus resursus, tuomet debesis nėra tinkama terpė jūsų programai.
  - Dinaminis atminties išplėtimas gal eksponentiškai pakelti kainą
- Daug kas iš senelių girdėjo frazę "**jei daiktas nėra sugedęs, tai nereikia jo taisyti**." Ir senelis yra teisus. Jei jūsų dabartinis sprendimas tinkamai atlieka savo funkcijas, kodėl ji reikia taisyti arba perdaryti?
- Debesų kompiuterijos **pliusai:**
  - Paprastumas
  - Scalability
  - Patikimi tiekėjai (Google, Amazon, ...)
  - Atlaisvina vidinius įmonės HR
  - Saugumas
  - Įvykių registravimas

---

- **LAMP** reiškia šių populiarių komponentų rinkinį:
  - Linux atviro kodo operacinė sistema
  - Apache atviro kodo žiniatinklio serveris
  - MySQL atviro kodo Struktūrinių užklausų kalba (SQL) reliacinių duomenų bazių interneto serveris
  - PHP/Perl/Python programavimo kalba
- **LAMP problemos:**
  - Neefektyvus gijų panaudojimas (arba nėra, arba sukonfigūruota lievai)
  - MySQL nesiscalina

---

- Cloud **saugumo** problemos:
  - Viskas kas įdedama į debesis gali būti prieinami visiems
  - Programišiai paprastai nėra geri žmonės.

## Debesų kompiuterijos standartai

- **Komunikacija**:
  - **HTTP** - [Interneto Technologijos](https://edriskus.github.io/6-semestras/Interneto%20Technologijos/konspektas)
  - **XMPP** (Extensible Messaging and Presence Protocol) - leidžia realizuoti dvipusį ryšio ir eliminuoją pastovų žinučių siuntinėjimą (polling ). XMPP didžiausia problema yra ta, kad **tai nėra HTTP**, jie net nėra panašūs. Yra manoma, kad nauji standartai turi būti grindžiami esamais interneto standartais, ir kol HTTP veikia patenkinamai, XMPP nebus tobulas, ypač debesų kompiuterijai, koks geras jis bebūtų.
- **Saugumas:**
  - **SSL** (Secure Sockets Layer) - Norėdami sukurti SSL ryšį, interneto serveris turi turėti SSL sertifikatą. Kai debesų kompiuterijos paslaugų teikėjas pradeda SSL sesiją, jie turi pateikti informaciją apie bendrovės ir interneto svetainės tapatybes. Vėliau teikėjo kompiuteris sukuria du šifravimo raktus - viešąjį raktą ir privatų raktą.
    1. Naršyklė patikrina svetainės SSL sertifikatą, kad įsitikinti, jog svetainė, prie kurios jūs jungiatės, yra tikra, o ne kažkas kitas perėmė jos valdymą, ar sukūrė kloną.
    2. Naršyklė ir interneto svetainė nusprendžia, kokio tipo šifravimą naudoti.
    3. Naršyklė ir serveris siunčia vienas kitam unikalius kodus, kurie bus naudojami šifruojant informaciją kuri turi būti išsiųsta.
    4. Naršyklė ir serveris naudoja šifravimą ir inicijuoja informacijos mainus.
    5. Naršyklė rodo šifravimo piktogramą ir interneto puslapiai yra perduodami šifruotu pavidalu.
  - **OpenID** - atviro kodo sprendimas, realizuojantis galimybę prieiti prie įvairių interneto svetainių su unikaliais vartotojo vardais ir slaptažodžiais.
  - **PCI DSS** - Mokėjimo kortelių duomenų saugumo standarto (Payment Card Industry Data Security Standards - PCI DSS) 2.2.1 reikalavimas
- **Klientai**:
  - **HTML** - [Interneto Technologijos](https://edriskus.github.io/6-semestras/Interneto%20Technologijos/konspektas)
  - Dynamic HTML, or **DHTML**, is an *umbrella* term for a collection of technologies used together to create interactive and animated websites by using a combination of a static markup language (such as HTML), a client-side scripting language (such as JavaScript), a presentation definition language (such as CSS), and the Document Object Model (DOM).
- **Infrastruktūra:**
  - **Virtualizacija:**
    - Kaip **VMware** ir partnerių pastangų rezultatas buvo sukurtas standartas vadinamas Atviru Virtualizacijos formatu (**Open Virtualization Format - OVF**). OVF aprašoma, kaip virtualūs prietaisai gali būti aprašomi nuo kūrėjo nepriklausomu būdu, kad juos galima būtų paleisti ant bet kurio hypervizorio.
- **Duomenys:**
  - **JSON** (JavaScript Object Notation) - Tai labai geras pakaitalas XML, kai JavaScript yra naudojamas realizuojant duomenų mainus, pavyzdžiui, dirbant su AJAX.
  - Extensible Markup Language (**XML**) yra standartinis būdas koduoti tekstus ir duomenis. Labai panašu į HTML, tik yra pora skirtumų:
    - Formos ir turinio atskyrimas. HTML naudoja žymes, apibrėžiančias teksto išvaizdą, o XML naudoja žymės apibrėžiančias struktūrą ir duomenų turinį. Atskiri taikymo variantai bus nurodomi programoje arba stiliaus lape.
    - XML yra praplečiamas. Naujos žymės gali būti apibrėžtos konkrečios programos kūrėjų, HTML žymes apibrėžia W3C.
- **Web paslaugos**:
  - Representational state transfer (**REST**) yra būdas gauti informaciją iš interneto svetainės skaitant pasirinktą tinklalapį, kuriame yra **XML** failas, aprašantis norimą turinį.
  - **SOAP** (Simple Object Access Protocol) yra būdas, leidžiantis programai veikiančiai vienos rūšies operacinėje sistemoje (pavyzdžiui, Windows 7) susisiekti su kita programa, veikiančia tos pačios, ar kitos rūšies operacinėje sistemoje (pavyzdžiui, Linux), naudojant HTTP ir XML kaip įrankius keistis informacijai.
    - SOAP tiksliai apibūdina, kaip koduoti HTTP antraštę ir XML failą, kad viename kompiuteryje esanti programa galėtų susisiekti su programa kitame kompiuteryje ir perduoti jai informaciją. Jis taip pat paaiškina, kaip kviečiama programa gali grąžinti atsakymą.
    - Vienas iš SOAP privalumų yra tai, kad programos užklausos lengviau pereina per užkardas, kurios paprastai blokuoja specifinius duomenų srautus. HTTP užklausos paprastai yra praleidžiamos per ugniasienes, programos, naudojančios SOAP gali bendrauti su programomis bet kur, kur veikia interneto ryšis.