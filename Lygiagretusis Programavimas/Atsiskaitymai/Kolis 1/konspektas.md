# Lygiagretusis programavimas

## Įvadas

- **Lygiagretieji skaičiavimai** reikalingi:
    - Įgauti didesnius kompiuterinius pajėgumus tam, kad greičiau išspręsti vis didesnius uždavinius.
    - Lygiagrečios technologijos yra natūralus kelias didinti kompiuterių skaičiavimų greitį ir atminties resursus.
    - Paskutiniųjų dešimtmečių patirtis rodo, kad šis kompiuterinių technologijų vystymosi kelias yra ekonomiškai naudingiausias.
    - Todėl šiuo metu ne tik patys galingiausi pasaulyje bet ir personaliniai kompiuteriai yra lygiagretieji kompiuteriai.
- Kompiuterio skaičiavimo pajėgumai matuojami FLOPS (Floating point Operations Per Second) parodo kiek bazinių operacijų `+ - * /` su realiaisiais skaičiais atliekama per sekundę
- FLOPS laipsniai
    - kilo * 10^3
    - Mega * 10^6
    - Giga * 10^9
    - Tera * 10^12
    - Peta * 10^15
    - Exa  * 10^18
    - Zetta* 10^21
    - Yotta* 10^24
- Komerciniai LP taikymai:
    - Lygiagrečios duomenų bazės (data mining).
    - Web search engines, web based business services.
    - Naftos ir dujų išžvalgymas, gavyba.
    - Kompiuterinė diagnostika medicinoje (tomografija).
    - Vaistų dizainas.
    - Finansinis ir ekonominis modeliavimas.
    - Kompiuterinė grafika (rendering, virtual reality).
- Galingiausias superkompiuteris pasaulyje: **Sunway TaiguLight**:
    - 93 PFLOPS (*10^15)
    - Kinija
    - ~10k branduolių
- Nuo 2003 nebeauga GHz

## Nuosekliųjų kompiuterių architektūra

- **Von Neumann'o architektūra:
    - Kompiuterį sudaro **Atmintis**, **CPU** ir jos jungianti **magistralė**
    - Instrukcijos saugomos atmintyje taip pat, kaip duomenys, kuriuose jos turės apdoroti
    - CPU gauna (fetch) instrukcijas ir duomenis iš atminties ir nuosekliai jas vykdo
    - CPU viduje:
        - ALU atlieka veiksmus
        - Registrai saugo laikinus duomenis
        - IU (instruction unit) perduoda instrukcijas i ALU
- Šiuolaikiniai kompiuteriai stengiasi atlikti kuo daugiau veiksmų **per vieną taktą (clock)**
- The **von Neumann bottleneck** is the idea that computer system throughput is limited due to the relative ability of processors compared to top rates of data transfer. According to this description of computer architecture, a processor is idle for a certain amount of time while memory is accessed.

## Instrukcijų lygio lygiagretumas: Konvejeris (pipelining)

- Užduotis yra padalinama į m použdavinių (subtasks) T1, ..., Tm.
- Kiekvienas iš jų gali būti vykdomas nepriklausomai.
- Tarkime (paprastumui), kad kiekvienas použdavinys įvykdomas per tą patį laiką – τ. 
    - N uždavinių atlikimo laikas nuosekliuoju būdu – `TS(N) = N m τ`.
    - N uždavinių atlikimo laikas konvejerio būdu – `TP(N) = (m + N - 1)τ`.
- Kuo ilgesnis konvejeris, tuo didesnį pagreitėjimą mes gauname, jei galime laikyti jį užpildytų uždavinių srautu.
- **Instrukcijų Konvejeris** nesumažina vienos atskiros instrukcijos atlikimo laiką, o padidina jų pralaidumą (angl. throughput), tuo pačiu padidindamas procesoriaus našumą.
- Jei atsiranda sąlygos instrukcija - naudojamas **„branch predicting“** įrenginys procesoriuje, kuris bando atspėti teisingą instrukcijų srauto šaką ir spekuliatyviai pradeda jos vykdymą konvejeryje. Jei jis atspėja neteisingai, konvejerio turinys turi būti išvalytas (angl. pipeline’s flush)...

---

- **“vektoriniai procesoriai”** realizuoja ne tik instrukcijų bet ir duomenų konvejerį. Specialios instrukcijos nusako procesoriui atlikti reikalingą veiksmą iškarto su tam tikrais atminties segmentai - vektoriais (vietoj N instrukcijų su atskirai gaunamais skaičiais).
- Problemos: sudėtingas CPU dizainas ir sudėtingos instrukcijos (jų dekoderiai) sulėtina atskirų paprastų instrukcijų atlikimą (a+b). Efektyvumui reikia didelių N !
- Vektoriniai procesoriai dominavo superkompiuteriuose nuo 70-ų iki 90-ų metų. Dauguma šiuolaikinių procesorių turi vek-torinių operacijų įrenginius: VIS, MMX, SSE, AltiVec ir AVX.
- Procesorius, įvykdantys daugiau negu vieną instrukciją per taktą, vadinamas **superskaliariniu (superscalar)**. Jis turi turėti keletą vykdančių įrenginių (pvz. ALU, FPU, SIMD):
    - Keletas funkcinių įrenginių
    - Valdantysis įrenginys (**dispatcher**), kuris nusprendžia, kurios operacijos gali būti lygiagretinamos
- **Very Long Instruction Word (VLIW) procesoriams** nereikia **dispatcherio** (nes siaip jis brangus labai) - jie kompiliavimo metu uzkoduoja, ka galima islygiagretinti:
    - Taigi, paprastesnė techninė įranga (hardware), tačiau sudėtingesnė programinė (software). Iš vienos pusės kompiliatorius turi visą programą (didesnis kontekstas), iš kitos jis neturi  “runtime” informacijos.

---

- Kompiuterių **atminties** charakteristikos:
    - **Uždelsimas** (latency) – tai laikas nuo atminties užklausos iki laiko momento, kai pirmas duomuo pasieks procesorių.
    - **Pralaidumas** (bandwidth) – tai greitis (pvz. baitai per sekundę), kuriuo duomenys iš atminties pasiekia procesorių.
    - **“Cache”** –  (buferinė / spartinančioji atmintinė) yra greitesnė atmintis, kurioje išsaugomos persiunčiamų duomenų iš pagrindinės atminties (RAM) kopijos, greitam jų pasiekimui pakartotinio panaudojimo atveju.
    - Šiuolaikiniai procesoriai turi keletą hierarchinių „cache“ lygių pagal jų greitį ir dydį: L1, L2, L3.

## Lygiagrečiųjų kompiuterių architektūra

- Klasifikacija pagal instrukcijų ir duomenų kiekius (Flyno **(M. Flynn)** klasifikacija (1966)):
    - **SISD**:
        - **Nuoseklus** tipas - klasikins von Neumann modelis
        - Single Instruction: procesoriuje  yra apdorojimas vienas instrukcijų srautas (nuosekliai: viena po kitos).
        - Single data: apdorojimų duomenų srautas yra irgi vienas. 
    - **SIMD**:
        - **Lygiagretus** tipas - GPU, vector pipelines / processor arrays
        - Tokio tipo architektūroje turi būti vienas valdantysis įrenginys (control unit, instruction dispatcher) ir keletas PE.
        - Ši architektūra labai gerai tinka uždavi-niams su tam tikru reguliarumu, su vektoriais, matricomis: tiesinė algebra, vaizdų apdorojimas (image processing).
    - **MISD**: 
        - Prieštaringai vertinama, ar egzistuoja šios architektūros tipo pavyzdžiai, ar tai “tikrieji” kompiuteriai.
        - Tokio tipo lygiagreti architektūra naudo-jama specializuotuose kompiuteriuose: filtruose, dekoderiuose ar kritinių sistemų dubliavimui
    - **MIMD**: 
        - **Lygiagrečiosios** architektūros tipas - beveik visi šiuolaikiniai kompiuteriai priklauso šitam tipui. 
        - Multiple Instruction: kiekvienas procesorius (valdantysis ir vykdantysis įrenginys(-iai)) gali vykdyti skirtingą instrukcijų srautą.
        - Multiple Data: kiekvienas procesorius gali dirbti su skirtingu duomenų srautu.
- SIMD architektūra yra paprastesnė ir reikalauja mažiau “hardware” negu MIMD (tik vienas “control unit”).
- Tačiau SIMD procesoriai tinka ne visiems uždaviniams.
- SIMD procesoriai reikalauja specialaus dizaino, todėl jų projektavimas ir gamyba gaunasi brangesnė (pvz. vektoriniai procesoriai). 
- MIMD tipo lygiagrečiųjų kompiuterių procesoriuose dažnai naudojami SIMD tipo įrenginiai

---

- Klasifikacija lygiagrečiojo kompiuterio atminties tipą:
    - **Bendrosios atminties** (shared memory) kompiuteriai.
        - Gali but naudojama SIMD ar MIMD architekturose. 
        - Visi procesoriai gali saveikauti vienas su kitu bendraja atmintimi. Tačiau iškyla problema, kaip užtikrinti norimą veiksmų/operacijų atlikimo tvarką, kai keli procesoriai tuo pačiu metu dirba su tais pačiais duomenimis.
        - Skirstomi pagal atminties pasiekiamumo laika:
            - **UMA** (uniform memory access):
                - tolygus (vienodas) atminties pasiekimo (skaitymo/rašymo) laikas visiems procesoriams.
                - (cache coherency): kai vienas iš procesorių pakeičia kintamojo reikšmę, jo kopijos kitų procesorių spartinančiose atmintinėse tampa neteisingomis
            - **NUMA** (non)
                - Bendroji atmintis fiziskai padalinta tarp procesoriu
                - Min. 3 skirtingi greiciai (local, extrenal, cache)
                - Labiau ispleciama
        - Pagrindinis trūkumas - bendrą atmintį naudojančios sistemos sunkiai išplečiamos: sudėtinga, brangu ir ne visada efektyvu, nes stipriai padidina tinklo apkrovimą. + Cache Coherency problem
    - **Paskirstytosios atminties** (distributed memory) kompiuteriai.
        - Nėra jokio bendro atminties adresavimo, **kiekvienas procesorius adresuoja tik savo atmintį**.
        - Programuotojo uzdavinys - suderinti, kaip ir kada duomenys siunciami tarp procesoriu
        - **Privalumai** - ispleciamumas, mazesne kaina, nera cache coherency
        - **Trukumai** - zymiai sudetingiau programuoti
    - Mišrios **distributed-shared** sistemos: viduje naudojama UMA/NUMA, bet mazgai sujungti paskirstytai

## Procesorių sujungimo tinklai (topologija)

- Stacionarieji tinklai turi **fiksuotas jungtis** tarp mazgų. Pvz., žiedinis, žvaigždinis tinklai.
    - **Visiskai jungus** - visi node sujugnti tarpusavyje. geriausios topologinės charakteristikos, bet per brangus dideliems p.
    - **Zvaigzdinis** - 1 centrinis node jungiasi su kitais. abai pigus, bet turi labai maža jungumą ir plotį. Tačiau gerai tinka šeimininkas-darbininkai (master-slave) algoritmams. Pvz.: LAN connected with HUB.
    - **Tiesinis** - nodes jungiasi eiles isdestymu. per didelis skersmuo ir labai mažas plotis.
    - **Ziedinis** - ring, tik jungiasi pirmas su paskutiniu. per didelis skersmuo ir labai mažas plotis.
    - **2D mesh** - daug tiesiniu, sujungtu atitinkamais elementais kaip tiesinis tinklas. Geros topologinės savybės. Gana lengvai gaminami ir išplečiami. Labai gerai tinka matricinėms operacijoms
    - **2D torus** - ziedinio 2D analogija. --||--
    - **Hiperkubas** - kiekviena nauja dimensija daroma kopijuojant -1 dimensija ir sujungiant atitinkamas nukopijuotas virsunes. labai geros topologinės savybės. Gali emuliuoti kitas topologijas (t.y. naudoti joms skirtus algoritmus). Tačiau gamyba yra brangoka didelėms p.
    - **Binary tree* - medis
    - **Fat tree** - kuo storesne jungtis - tuo daugiau pralaidumo
    ---
    - **Atstumu** tarp dviejų tinklo mazgų vadiname trumpiausio kelio nuo vieno mazgo iki kito ilgį.
    - **Skersmuo** (diameter) – didžiausias atstumas tarp dviejų tinklo mazgų (number of hops). Kuo mažesnis yra tinklo skersmuo, tuo greičiau bus persiunčiami pranešimai.
    - **Tinklo** jungumas (arc connectivity) – mažiausias jungčių skaičius, kurias pašalinę galime atskirti tinklo dalį nuo likusio tinklo. Charakterizuoja gausybę skirtingų kelių tarp bet kurių dviejų tinklo mazgų. Kuo didesnis tinklo jungumas, tuo mažesnė tikimybė, kad persiunčiant pranešimą reikės laukti, kol ta pačia jungtimi pasinaudos kiti procesoriai.
    - **Tinklo** plotis (bisection width) – mažiausias jungčių skaičius, kurias pašalinę tinklą padalijame į dvi lygias dalis. Apibūdina kritinį blogiausią tinklo pralaidumą tarp dviejų jo dalių.
    - **Tinklo** kaina (cost) – bendras tinklo jungčių skaičius. Kuo daugiau naudojama jungčių, tuo sunkiau tokį tinklą realizuoti techniškai ir tuo didesnė jo kaina.

---

- Dinaminiuose tinkluose jungtys gali būti dinamiškai perjungiamos. Taigi, dinaminiai tinklai turi dar **perjungiklius (angl. switches)**. Pvz., skersinių perjungimų tinklas (angl. crossbar).
    - **Magistralinis tinklas (BUS)** - Procesoriai ir atminties moduliai yra sujungiami bendruoju keliu (shared bus). Ribotas pralaidumas, mažas išplečiamumas - pvz multicore, SMP kompiuteriai. Procesorių/branduolių skaičius auga: 2, 4, 8, 16, 32 (bet yra nedidelis).
    - **Skersinių perjungimų tinklas (crossbar switching network)** - labai geras pralaidumas, bet didele kaina ir blogas ispleciamumas
    - **Daugiažingsniai tinklai (Multistage Networks)**
        - **Omega tinklas** :
            - Kiekvienoje sekcijoje jungtys yra suskirstytos poromis ir sujungtos 2×2 perjungiklių (komutatorių, switches) pagalba. Iš viso yra p/2 perjungiklių kiekvienoje sekcijoje (žingsnyje).
            - Kiekvienas perjungiklis gali veikti dviem režimais: tiesus perdavimas (pass-through), kai pranešimas nekeičia krypties, ir kryžminis perdavimas (crossover), kai pranešimas persiunčiamas į gretimą kanalą.

## Lygiagreciuju algoritmu analize

- Algoritmo sudėtingumas – algoritmo bazinių operacijų skaičius.
- Uždavinio dydžiu (arba apimtimi) vadinamas geriausio žinomo jo sprendimo algoritmo sudėtingumas.
- Uždavinio duomenų dydis – naudojamų duomenų kiekis.

### Asimptotiniai iverciai

- **Upper Bound** - Tegul f = f (n) ir g = g(n) yra dvi funkcijos, kurios yra apibrėžtos natūraliųjų skaičių aibėje, o jų reikšmės yra teigiamieji skaičiai. Sakysime `f(n) = O(g(n))`, jei egzistuoja `const c > 0` ir `n prikl. N` kad `0 <= f(n) <= cg(n)` kai `n >= n0`.
    - `f(n) = O(g(n))` reiškia, kad funkcija f(n) asimptotiškai didėja ne greičiau, nei g(n), padauginta iš konstantos. 