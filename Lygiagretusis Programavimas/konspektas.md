# Lygiagretusis programavimas

*WORK IN PROGRESS...*

- [Lygiagretusis programavimas](#lygiagretusis-programavimas)
  - [1. Lygiagrečiųjų algoritmų sudėtingumo teorija](#1-lygiagre%C4%8Di%C5%B3j%C5%B3-algoritm%C5%B3-sud%C4%97tingumo-teorija)
  - [2. Lygiagrečiųjų algoritmų sudarymo etapai](#2-lygiagre%C4%8Di%C5%B3j%C5%B3-algoritm%C5%B3-sudarymo-etapai)
  - [3. Lygiagrečiųjų algoritmų atvaizdavimas panaudojant grafus](#3-lygiagre%C4%8Di%C5%B3j%C5%B3-algoritm%C5%B3-atvaizdavimas-panaudojant-grafus)
  - [4. Aplikacijų programavimo sąsaja OpenMP](#4-aplikacij%C5%B3-programavimo-s%C4%85saja-openmp)
  - [5. Standartas MPI](#5-standartas-mpi)
  - [6. NVIDIA GPU įrenginio architektūra](#6-nvidia-gpu-%C4%AFrenginio-architekt%C5%ABra)
  - [7. CUDA programavimo modelis](#7-cuda-programavimo-modelis)

Jei reikės - koliokviumo konspektas [čia](https://edriskus.github.io/6-semestras/Lygiagretusis%20Programavimas/Atsiskaitymai/Kolis%201/konspektas)

## 1. Lygiagrečiųjų algoritmų sudėtingumo teorija

- *Spartinimo koeficiento sąvoka ir jos taikymas. Algoritminis spartinimo koeficientas*
  - Algoritmas - tiksliai apibrėžta skaičiavimo procedūra, kuria, imdami pradinius duomenis ir atlikę baigtinį skaičių operacijų, gauname rezultatus
  - Algoritmo sudėtingumas - algoritmo bazinių operacijų (priklauso nuo uždavinio) skaičius.
  - Uždavinio dydžiu (arba apimtimi) vadinamas geriausio žinomo jo sprendimo algoritmo sudėtingumas.
  - Lygiagrečiojo algoritmo **spartinimo koeficientu** (angl. speedup) vadinamas santykis:
    - `S(N, P) = T0(N) / Tp(N)`
    - T0(N) - nuosekliojo algoritmo laikas
    - Jis įvertina pagreitėjimą, kurį pasiekiame spręsdami uždavinį lygiagrečiuoju algoritmu naudojant `P` procesų.
  - **Algoritminis spartinimo koeficientas**:
    - `^s(N, P) = T1(N) / Tp(N)`
    - Naudojamas kai `T0(N) < T1(N)`
- *Efektyvumo koeficiento sąvoka ir jos taikymas*
  - Lygiagrečiojo algoritmo **efektyvumo koeficientu** (angl. efficiency) vadinamas santykis
  - `E(N, P) = S(N, P) / P`
  - Kai `T0 = T1`, efektyvumo koeficientas parodo kaip efektyviai naudojami procesoriai (branduoliai), vykdant lygiagretųjį algoritmą, kokią laiko dalį procesoriai atlieka naudingą darbą.
- *Papildomi lygiagrečiųjų algoritmų kaštai*
  - Duomenų persiuntimo (communication)
  - Sinchronizacijos (idle time) - *Prastovos, kai laukiama kito proceso(-ų), kol jis(arba jie) pabaigs savo skaičiavimų dalį*
  - Tik lygiagrečiam algoritmui būdingi papildomi skaičiavimai (extra, redundant computation)
- *Amdahlo dėsnis, jo priežasties paaiškinimas, išvados*
  - **Amdahlo dėsnis** - Sprendžiant tą patį uždavinį su vis daugiau lygiagrečiųjų procesų gaunamas pagreitėjimas yra apribotas.
  - `S(N,P) <= 1 / (s + r/P)
    - `r` yra algoritmo dalis, kurią galima apskaičiuoti lygiagrečiai, o  `s = 1 – r` yra likusioji algoritmo dalis, kurią galime vykdyti tik nuosekliai
  - **Įrodymas:** `T0(N) < T1(N)`
  - Net ir turint begalo daug procesorių (branduolių ir t.t.), lygiagrečiojo algoritmo pagreitėjimas (vykdymo laiko sumažėjimas) **yra apribotas jo nuosekliąja dalimi**
- *Apibendrintasis Amdahlo dėsnis, jo priežasties paaiškinimas, išvados*
  - **Apibendrintasis Amdahlo dėsnis** (Gustafson Law) - didinant uždavinio dydį N fiksuotam procesų skaičiui P, lygiagrečiojo algoritmo spartinimo koeficientas artėja į P, o efektyvumas į 100%.
    - **Išvada.** Lygiagretieji algoritmai yra vis efektyvesni, kai sprendžiame vis didesnio dydžio uždavinius.
- *Algoritmo išplečiamumo sąvoka*
  - Iš vienos pusės lygiagrečiojo algoritmo **efektyvumas mažėja**, kai *procesų skaičius yra didinamas* fiksavus uždavinio dydį (Amdahlo dėsnis).
  - Iš kitos, *fiksavus procesų skaičių* ir didinant uždavinio dydį, **efektyvumas didėja** (apibendrintas Amdahlo dėsnis).
  - **Išplečiamumas** - Kokiu greičiu turi didėti uždavinio dydis, kad taip pat efektyviai naudotume vis daugiau procesų
  - **Uždavinio dydžiu** vadinamas geriausio žinomo jo sprendimo algoritmo sudėtingumas, t.y šio algoritmo bazinių operacijų skaičius. Žymėsime: `W = T0(N)`
- *Lygiagrečiojo algoritmo kaina ir papildomos sąnaudos*
  - **Kaina** - `C(N, P) = P * Tp(N)` - kiek kainuoja (panaudoja procesorių (branduolių) laiko) uždavinio sprendimas šiuo algoritmu su P procesais
  - **Pilnosiomis papildomomis sąnaudomis** (angl. total overhead) vadiname dydį `K(W, P) = C(N, P) - W`
- *Algoritmo lygiagretumo laipsnis ir jo taikymas. Vektorių skaliarinės sandaugos lygiagretinimas*
  - Didžiausią skaičių procesorių, kuriuos galime naudoti realizuodami duotąjį lygiagretųjį algoritmą, vadinsime **algoritmo lygiagretumo laipsniu** (angl. degree of concurrency) `P = D(W)`
- *Duomenų persiuntimo kaštų įvertinimas – alpha ir beta kaštai*
  - `α` - laikas, per kurį pranešimas yra paruošiamas siutimui, inicializuojamas tinklas ir t.t.
  - `β` - vieno skaičiaus siuntimo laikas
  - Vieno pranešimo (iš n skaičių) persiuntimo laiką galima įvertinti formule:
    - `T = α + β * n`
  - **Kanalo/linijos plotis** (tinklo greitis) - `1 / β * NumOfBits`

## 2. Lygiagrečiųjų algoritmų sudarymo etapai

- Šiuolaikiniai kompiliatoriai, turintys automatinio išlygiagretimo opciją, bando automatiškai išlygiagretinti tik programoje esančius ciklus. To toli gražu nepakanka - kol kas lygiagrečiųjų algoritmų sudarymas ir programinis realizavimas specialių funkcijų ir direktyvų pagalba lieka programuotojo uždaviniu
- *Uždavinio išskaidymas*
  - **Srities/duomenų išskaidymas** (angl. domain decom-position), kai atliekami tie patys veiksmai, tik su skirtingais duomenimis.
  - **Funkcinis išskaidymas** (angl. functional decomposi-tion), kai atliekamos skirtingos funkcijos su tais pačiais arba skirtingais duomenimis.
- *Ryšių tarp užduočių nustatymas*
  - Akivaizdu, kad kiekviena užduotis sprendžiama su tam tikrais pradiniais duomenimis.
  - Kai bent dalį šių duomenų gauname išsprendę kitą užduotį (arba užduotis), gauname eiliškumo ryšius tarp tų užduočių.
  - Taigi, reikia nustatyti, kada kokia užduotis gali būti sprendžiama, kokie duomenys jai turi būti perduoti
- *Užduočių paskirstymas tarp procesų*
  - Paskirstant užduotis, siekiame, kad užduoties atlikimui reikalingi duomenys jau priklausytų atitinkamam procesui.
  - Optimalus užduočių paskirstymas tarp P procesų, t.y. tas kuris minimizuoja lygiagretaus algoritmo atlikimo laiką TP, turi siekti kompromiso tarp **minimalių sinchronizacijos ir galimai laukimo kaštų** bei **tolygaus procesorių apkrovimo**.

## 3. Lygiagrečiųjų algoritmų atvaizdavimas panaudojant grafus

- Lygiagretųjį algoritmą galime atvaizduoti orientuotu acikliniu grafu `G = (T, P)`, kur `T`  yra grafo viršūnių aibė, o `P`  – orientuotų grafo briaunų aibė. Grafo **viršūnių svoriai** rodo šių užduočių vykdymo laiką
- *Lygiagretumo laipsnis*
  - Lygiagrečiojo algoritmo **lygiagretumo laipsniu** (angl. degree of concurrency) vadinamas didžiausias skaičius užduočių, kurios gali būti sprendžiamos tuo pačiu metu.
- *kritinio kelio ilgis*
  - Lygiagrečiojo algoritmo **kritinio kelio ilgiu** (angl. critical path length) vadinamas jo grafo ilgiausio kelio ilgis. Kelio ilgis apskaičiuojamas kaip jo viršūnių (ir briaunų) svorių suma.
- *Užduočių tvarkaraštis ir jo sudarymas*
  - Užduočių sprendimo su P procesais tvarkaraščiu vadinsime vektorių S = {s1, ..., sn }, kurio elementas sj yra j-ajam procesui tekusių nj užduočių aibė.
  - Tvarkaraštis vadinamas **korektišku**, jei įvykdytos šios dvi sąlygos:
    - Kiekviena užduotis priklauso tik vienai aibei sj.
    - Kiekvienos užduoties vykdymo eilė yra didesnė už visų jos pirmtakių užduočių, priklausančių tai pačiai aibei, vykdymo eilę.
- *Ganto schema*
  - Lygiagretaus algoritmo užduočių sprendimo tvarkaraštis dažniausiai vaizduojamas **Ganto schema** (angl. Gantt chart).
  - Ją sudaro P procesų **laiko juostos**, kuriose pažymima, kada kiekviena užduotis pradedama spręsti ir kada baigiama.

## 4. Aplikacijų programavimo sąsaja OpenMP

- *Paskirtis, veikimo principai, privalumai, trūkumai*
  - **OpenMP** (Open specification for Multi-Processing) - priemonė, kurios pagalba iš nuoseklios programos būtų galima gauti lygiagrečiąją paprasčiau – beveik automatiškai. **Bendrosios atminties programavimas**.
  - **Privalumai**:
    - OpenMP gali “išlygiagretinti” (parallelize) daugybę nuoseklių programų tik su keletu papildomų paprastų instrukcijų pagalba.
    - Tos instrukcijos yra aukšto lygio (high-level API), nurodo lygiagretumą ir duomenų priklausomybę
    - Bendras (angl. unified) kodas nuosekliai ir lygiagrečiai versijai.
  - **Trūkumai**:
    - Neusteikia automatinio išlygiagretinimo.
    - Neusteikia Garantuoto pagreitėjimo.
    - Nesuteikia laisvės nuo klaidų, pvz., lenktynių konfliktai (data races).
- *Direktyvos ir funkcijos:*
  - **Direktyvos**:
    - Lygiagrečiosios srities (parallel regions)
    - Užduočių paskirstymo (work sharing)
    - Sinchronizavimo (synchronization)
  - Bibliotekos **funkcijos** (runtime functions)
    - `omp_set_num_threads()` - Nurodyti, sužinoti gijų skaičių
    - `omp_get_thread_num()` - Gauti gijos ID (unikalų identifikuojantį numerį)
- `#pragma omp parallel [clause [clause] ...]`
  - Kai pradinis procesas pasiekia šią direktyvą, jis sukuria gijų grupę ir toliau struktūrinį bloką (vieną sakinį arba sakinių bloką `{...}`) visos gijos atlieka **lygiagrečiai**.
  - Argumentai [clause]:
    - `if (scalar_expression)`
    - `private(list)`
    - `firstprivate(list)`
    - `default(shared | none)`
    - `shared(list)`
    - `copyin(list)`
    - `reduction(operator: list)`
    - `num_threads(integer-expression)`
  - **Papildomos** užduočių paskirstymo direktyvos, veikiančios `parallel` viduje:
    - `#pragma omp for` - Lygiagrečiąją sritį vykdančios gijos lygiagrečiai atlieka ciklo iteracijas. Iteracijų paskirstymo būdą nusako parametras `schedule` (`static | dynamic | guided`)
    - `#pragma omp sections` (ir `#pragma omp section` viduje) - Lygiagrečiąją sritį vykdančios gijos lygiagrečiai atlieka skirtingas sekcijas (struktūrinius blokus). Kiekviena sekcija bus atlikta tik vieną kartą vienos iš grupės gijų.
    - `#pragma omp single` - Pirmoji gija, kuri vykdydama lygiagrečiąją sritį pasieks šią direktyvą, imsis vykdyti nurodytą struktūrinį bloką, o kitos gijos jį praleis ir lauks konstrukcijos pabaigoje (jei nenurodytas argumentas `nowait`).
- `#pragma omp barrier`
  - Kai gija pasiekia šią direktyvą, ji sustoja ir laukia, kol visos kitos šios lygiagrečiosios srities gijos pasieks šį barjerą.
  - Kai tai atsitiks, visos šios gijos tęs programos vykdymą toliau.
  - OpenMP pats įstato (**neišreikštinius**) barjerus užduočių paskirstymo (`for`, `sections`, `single`) konstrukcijų pabaigoje, jei nenurodytas argumentas `nowait`.
- `#pragma omp for schedule()`
  - `schedule(static [,chunk])` - Iteracijų blokai (po chunk iteracijų) statiškai (prieš ciklo vykdymą) cikliniu būdu **paskirstomi tarp gijų**. Kai bloko dydis (chunk) nenurodytas, imamas maksimalus – Num_iter / num_threads. Pvz., Num_iter = 16, num_threads = 4
  - `schedule(dynamic[,chunk])` - Iteracijų blokai (po chunk iteracijų) dinamiškai (ciklo vykdymo metu) yra **priskiriami atsilaisvinančioms** (atlikusioms anksčiau priskirto bloko iteracijas) gijoms. Jei bloko dydis nenurodytas, jis imamas lygus vienetui.
  - `schedule(guided[,chunk])` - **Mažėjantys iteracijų blokai** yra dinamiškai priskiriami gijoms. Bloko dydis=max(Number_iterations_remaining / num_threads, chunk). Pagal nutylėjimą: default chunk=1.
  - `schedule(runtime)` - Programos vykdymo metų tvarkaraščio tipas (schedule) ir bloko dydis (chunk) yra **paimami iš aplinkos** kintamojo OMP_SCHEDULE (environment variable).

## 5. Standartas MPI

- *Paskirtis, veikimo principai (4 pagrindinės koncepcijos), privalumai, trūkumai*
  - **Paskirstytos atminties programavimas**
  - Kiekvienas iš paleistų lygiagrečiųjų procesų vykdo tą patį programinį kodą. Visi procesai automatiškai yra numeruojami ir gauna unikalų numerį – ID – angl. rank, kurį kiekvienas procesas gali sužinoti MPI funkcijos pagalba
  - **Privalumai:**
    - **Standartas**. Šiuo metu MPI yra pripažintas standartas, kuris išstūmė kitus paskirstytos atminties programavimo (su pranešimų persiuntimu) įrankius ir bibliotekas.
    - **Portatyvumas**. MPI standartą realizuojančios bibliotekos (nemokamos ir komercinės) egzistuoja visose platformose. Todėl MPI programa be pakeitimų gali būti perkelta iš vieno tipo kompiuterio į kito tipo kompiuterį.
    - **Našumas**. MPI programų kompiliavimas su gamintųjų (angl. vendor) MPI realizacijomis, optimizuotomis atitinkamose platformose, leidžia gerinti pačių lygiagrečiųjų programų efektyvumą.
    - **Funkcionalumas**. Vien tik MPI-1 standartas apibrėžia virš 120 funkcijų, kurios leidžia programuotojui realizuoti ne tik bazines duomenų persiuntimo operacijas, bet ir sudėtingus grupinius duomenų mainus. Be to, šiuo metu jau yra sukurta (ir tebekuriama) nemažai įvairių aukštesnio lygio lygiagrečiųjų bibliotekų (pvz., matematinių), kurios remiasi išlygiagretinimu su MPI.
  - **Trūkumai:**
    - ...
  - MPI branduolį (MPI-1) sudaro keturios pagrindinės **koncepcijos**:
    - **Duomenų siuntimo operacijos (funkcijos)**:
      - “point-to-point” duomenų siuntimo operacijos (funkcijos): vienas procesas siunčia (siuntėjas) duomenis kitam procesui (gavėjas);
      - Kolektyvinės duomenų siuntimo operacijos (funkcijos): keli procesai (grupė) siunčia ir gauna duomenis vienu metu (pvz., surenka, paskirsto).
    - **Komunikatoriai** - specialus MPI objektas, kuris apibrėžia kažkokią lygiagrečiųjų procesų grupę ir priskiria jai unikalų (tarp visų kitų komunikatorių) požymį. Todėl ta pati procesų grupė gali turėti kelis komunikatorius.
    - **Siunčiamų duomenų tipai (sudarymo funkcijos)**:
      - MPI duomenų tipai leidžia sumažinti duomenų kopijavimo sąnaudas ir naudoti skaičiavimuose heterogenines sistemas (pvz., kartu naudoti 32 ir 64-bitų kompiuterius).
      - MPI leidžia programuotojui pačiam apibrėžti sudėtingesnius tipus (angl. derived data types).
    - **Virtualios topologijos** - leidžia programuotojui sudėlioti MPI procesų grupę pagal tam tikrą geometrinę topologiją (pvz., dekartinį tinklą, grafą).
- *6 pagrindinės MPI funkcijos*
  - `int MPI_Init( int *argc, char ***argv);` - Inicializuoja MPI vykdymo aplinką (MPI execution environment)
  - `int MPI_Finalize(void);` - Visos MPI vykdomos operacijos (pvz., duomenų persiuntimas) turi pasibaigti iki šios funkcijos iškvietimo. Po šios funkcijos negalima kviesti kitų MPI funkcijų, kitaip bus gauta klaida.
  - `int MPI_Comm_size (MPI_Comm comm, int *size);` - Funkcija nustato procesų skaičių komunikatoriuje comm ir grąžina jį į size. Programos pradžioje naudojama su MPI_COMM_WORLD komunikatoriumi tam, kad nustatyti programą vykdančių lygiagrečių procesų skaičių (t.y. kiek jų paleido vartotojas).
  - `int MPI_Comm_rank(MPI_Comm comm, int *rank);` - Funkcija nustato proceso, iškvietusio ją, unikalų numerį (ID, rank’a) nurodytame komunikatoriuje comm ir grąžina jį į rank.
  - `int MPI_Send( void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);`
    - **buf** – buferio, kuriame laikomi siunčiami duomenys, pradžios adresas (rodyklė),
    - **count** – siunčiamų duomenų elementų kiekis (skaičius),
    - **datatype** – siunčiamų duomenų elementų tipas (MPI tipas),
    - **dest** – proceso, kuriam siunčiamas šis pranešimas (t.y. gavėjo), numeris (rank’as) komunikatoriuje comm,
    - **tag** – šiam pranešimui programuotojo suteikiamas numeris (paprastai, kad butų galima šį pranešimą atskirti nuo kitų, bet jis (tag) nebūtinai turi būti unikalus, t.y. gali būti ir vienodas visiems siunčiamiems pranešimams),
    - **comm** – komunikatorius, kuriam priklauso abu procesai (ir siuntėjas, ir gavėjas).
  - `int MPI_Recv( void *buf, int count, MPI_Datatype datatype, int source, int tag, MPI_Comm comm, MPI_Status *status);`
    - **buf** – buferio, į kurį bus patalpinti atsiusti duomenys, pradžios adresas (rodyklė),
    - **count** – gaunamų duomenų elementų kiekis (skaičius),
    - **datatype** – gaunamų duomenų elementų tipas (MPI tipas),
    - **source** – proceso, iš kurio turi būti gautas šis pranešimas (t.y. siuntėjo), numeris (rank’as) komunikatoriuje comm, arba MPI_ANY_SOURCE konstanta (wild card), jei šitoje programos vietoje pranešimas gali būti priimtas iš pirmo atsiuntusio proceso,
    - **tag** – gaunamo pranešimo numeris (šis numeris turi sutapti su tag numeriu, nurodytu siunčiant) arba MPI_ANY_TAG konstanta, jei nenorima tikrinti gaunamo pranešimo numerį (bus gautas pranešimas su bet kokiu tag numeriu).
    - **comm** – komunikatorius, kuriam priklauso abu procesai,
    - **status** – rodyklė į MPI duomenų struktūrą, į kurią bus įrašyti įvykusios duomenų gavimo operacijos duomenys (source, tag, message size).
- *Blokuotos ir neblokuotos MPI funkcijos*
  - **Blokuota** (blocking) MPI funkcija blokuoja proceso, iškvietusio ją, vykdymą, kol šios funkcijos apibrėžta operacija nebus užbaigta.
    - `MPI_Ssend`
    - `MPI_Bsend`
    - `MPI_Send`
    - `MPI_Rsend`
  - **Neblokuota** (blocking) MPI funkcija nelaukia operacijos pabaigos, o perduoda jos vykdymą MPI bibliotekai, kuri atliks ją, kai tik tai taps įmanoma (be papildomų nurodymų iš programuotojo), ir pasibaigia.
    - `MPI_Issend`
    - `MPI_Ibsend`
    - `MPI_Isend`
    - `MPI_Irsend`

## 6. NVIDIA GPU įrenginio architektūra

- *Skaičiavimų vienetai (ALU)*
  - GPU susidaro iš 𝑁<sub>𝑆𝑀</sub> multiprocesorių (toliau SM, angl. streaming multiprocessor)
  - Vienas multiprocesorius turi 𝑁<sub>𝑚</sub> branduolių, sudarytų iš skaičiavimų modulių. Moduliai gali būti skirtingi - tai priklauso nuo konkrečios plokštės GPU architektūros.
  - Visi skaičiavimai ir duomenų siuntimai yra atliekami porcijomis, specialiais gijų apdorojimo vienetais, kurie operuoja gijų porcijomis (angl. warp).
  - Programuotojo užduotis – parašyti kodą taip, kad gijų porcijos veiktų efektyviai, remiantis jų veikimo principais ir NVIDIA rekomendacijomis.
- *Atminties struktūra*
  - **Pagrindinė atmintis**. Iš jos skaityti ir į ją rašyti gali visi CUDA branduoliai lygiagrečiai. 
    - Pagrindinė atmintis naudojama globaliajai ir lokaliajai atmintims saugoti. Jos skiriasi tik tuo, kad lokalioji yra rezervuota tam tikroms gijoms o iš globaliosios gali skaityti ir GPU ir CPU (kopijuojant).
  - Kiekvienas GPU multiprocesorius turi **greitąją atmintį** (padalintą į kelias rūšis), paprastai tai yra 10-100 kilobaitų eilės dydžio atmintis. Ją galima suskirstyti į šiuos tipus:
    - **Registrai**: Šiuo metu skaičiavimuose dalyvaujantiems duomenims talpinti skirta atmintis
    - **Bendroji atmintis**: . Yra prieinama skirtingų vieno multiprocesoriaus gijų, tačiau vieno multiprocesoriaus nėra prieinama kito multiprocesoriaus skaičiavimų moduliams.
    - **L1 cache atmintis**: – automatizuota bendrosios atminties versija, kurios panaudojimu rūpinasi kompiliatorius.
  - **L2 cache atmintis** – spartinančioji atmintis, kuri yra bendra visiems multiprocesoriams, greitesnę už pagrindinę bet lėtesnė už greitąją.
- *Duomenų srauto schema kai skaičiavimuose naudojamas GPU*
  1. Duomenys iš CPU atmintis kopijuojami į GPU amtintį
  2. GPU programa užkraunama ir paleidžiama, kuo efektyviau išnaudojant spartinančiąją atmintį (cache)
  3. Rezultatas kopijuojamas iš GPU atminties į CPU amtintį

## 7. CUDA programavimo modelis

- *Gijos, blokai ir jų loginis išsidėstymas (tinklas)*
  - ...
- *SIMT principas, gijų porcijų (angl. warp) darbo vykdymo ypatumai*
  - ...
- *GPU skaičiavimų pajėgumas (angl. compute capability)*
  - ...
- *Gijų užimtumas (angl. CUDA occupancy). Gijų skaičius ir CUDA branduolių skaičius*
  - ...
- *Mokėjimas paaiškinti CUDA kodą*
  - ...