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
  - ...
- *Direktyvos ir funkcijos:*
  - ...
- `#pragma omp parallel`
  - ...
- `#pragma omp barrier`
  - ...
- `#pragma omp for schedule()`
  - ...
- `omp_get_num_threads()`
  - ...
- `omp_get_thread_num()`
  - ...
- `Mokėjimas paaiškinti OpenMP kodą`
  - ...

## 5. Standartas MPI

- *Paskirtis, veikimo principai (4 pagrindinės koncepcijos), privalumai, trūkumai*
  - ...
- *6 pagrindinės MPI funkcijos*
  - ...
- *Blokuotos ir neblokuotos MPI funkcijos*
  - ...
- *Mokėjimas paaiškinti MPI kodą*
  - ...

## 6. NVIDIA GPU įrenginio architektūra

- *Skaičiavimų vienetai*
  - ...
- *Atminties struktūra*
  - ...
- *Duomenų srauto schema kai skaičiavimuose naudojamas GPU*
  - ...

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