# Dirbtinis intelektas ir žinių sistemos

## 1. Paieška būsenų erdvėje (Chapter 3)

- **Paieška** - procesas, kurio metu bandoma rasti seką veiksmų, vedančių prie užsibrėžto tikslo.
- **Būsenų erdvė** apibūdinama 4 savybėmis [N A S GD]:
  - N - sistemos būsenos
  - A - sprendimo proceso žingsniai
  - S - pirminės būsenos
  - GD - būsenos, kurios laikomos uždavinio sprendimu
- Būsenų erdvė atvaizduojama grafu (paieškos medžiu)

## 2. Paieška į plotį (Chapter 3)

- **Breadth-first search** - a simple strategy in which the root node is expanded first, then all the successors of the root node are expanded next, then their successors, and so on. In general, all the nodes are expanded at a given depth in the search tree before any nodes at the next level are expanded.
- Naudojama duomenų struktūra - **Queue** (FIFO)

## 3. Paieška į gylį (Chapter 3)

- **Depth-first search** always expands the deepest node in the current frontier of the search tree. The progress of the search is illustrated in Figure 3.16. The search proceeds immediately to the deepest level of the search tree, where the nodes have no successors. As those nodes are expanded, they are dropped from the frontier, so then the search “backs up” to the next deepest node that still has unexplored successors.
- Naudojama duomenų struktūra - **Stack** (LIFO)

## 4. Euristiniai paieškos algoritmai (Chapter 3)

- The **heuristic function** is a way to inform the search about the direction to a goal. It provides an informed way to guess which neighbor of a node will lead to a goal. There is nothing magical about a heuristic function. It must use only information that can be readily obtained about a node.
- **Euristiniai paieškos algoritmai** - tai algoritmai, kurie problemą išsprendžia greičiau nei klasikiniai metodai, ar tai randa apytikslį sprendinį, kai klasikiniai metodai to padaryti negali. Naudojant euristinę funkciją (kiekvienam uždaviniui unikali) galima stipriai optimizuoti perrinkimų skaičių.
- Admissable (**Priimtinos**) Euristikos - neturi pervertinti likusio atstumo (< už realią kainą);
- Populiariausi algoritmai, naudojantys euristines funkcijas:
  1. **Pirmas geriausias** - Naudokite įvertinimo funkciją f(n) kiekvienam mazgui. Išplėskite labiausiai pageidaujamą neišplėstą mazgą.
      - **Tiesmukiškas Pirmas-geriausias** - `f(n) = h(n
      )`
      - **A* paieška** - vengiama varianto, kuris pasirodo neoptimalus - `f(n) = g(n) + h(n)`. `g(n)` - nueitas kelias nuo starto iki n
  1. **Lokalios** paieškos algoritmai- ieškoma konfigūracijos, kuri tenkintų ribojimus, stengiamasi somehow pagerinti dabartinę būseną
  1. **Gradiento** paieška - ...
  1. **Modeliuojamo** atkaitinimo paieška- vengiame lokalaus minimumo kartais klysdami, tačiau palaipsniui tų klaidų skaičius mažėja
  1. **Lokalaus spindulio** paieška- sekame k būsenų, jas atsitiktinai sugeneruojam, kiekvienoje iteracijoje taip pat generuojame iš k būsenų. Jei pasiekiam tikslą, sustojam, jei ne imame k geriausių toliau.
  1. **Genetiniai** paieškos algoritmai- sekanti būsena gaunama sukryžminus tėvų būsenas, būsenų įvertinimo f-ja suteikia didesnes reikšmes geresnėms būsenoms

## 5. Žaidimai ir paieška (Chapter 5)

- Deterministic, fully observable environments in which two agents act alternately and in which the utility values at the end of the game are always equal and opposite
- The **minimax** value of a player is the smallest value that the other players can force the player to receive, without knowing the player's actions; equivalently, it is the largest value the player can be sure to get when they know the actions of the other players.

## 6. Problemos nusakomos ribojimo sąlygomis (Chapter 6)

- **Deterministinės**, kai agentas žino kokioje būsenoje bus
- **Nedeterministinės**, kai sensoriai teikia papildomos info apie aplinką.
- **Constraint Satisfaction Problems** - uždavinio sprendimas, kurio metu yra atsižvelgiama į nustatytus ribojimus. Standartiniame paieškos uždavinyje, struktūrinės žinios apie uždavinį buvo aprašomos euristikoje, tačiau constraint satisfaction problem būsena nusakoma kintamaisiais Xi(visi „mazgai“), kurių vertės parenkamos iš domenų Di(galimų reikšmių aibė), o galutinė būsena, tai kintamieji su reikšmėmis, tenkinančiomis ribojimus.
- Grafai:
  - binarinis- kiekvienas ribojimas sujungia du kintamuosius(personally įsivaizduoju kaip matricą)
  - ribojimų grafas- mazgai su kintamaisiais, lankai nusako ribojimus pvz.
- CSP variantai:
  - Diskretūs(netolygūs) kintamieji su:
    - Baigtine duomenų aibe (pvz. loginis CSPs)
    - Begaline aibe (pvz. grafiko sudarymas, kai neribojama pabaigos data)
  - Tolydūs kintamieji (matavimo prietaisų pradžios/pabaigos laikas
- Ribojimų variantai:
  - Unitariniai (riboja vienu kintamuoju)
  - Binariniai
  - Aukštesnės eilės (pvz. kokie nors kriptoaritmetiniai kur daugiau ribojimų turi)
- Realiame pasaulyje CSP sutinkamas sprendžiant priskyrimo, grafikų, resursų paskirstymo uždaviniuose.

## 7. Žinių vaizdavimas (Chapter 7)

- **Žinių bazė** (knowledge base) = formalioje kalboje užrašyta sakinių aibė
- **Žinių vaizdavimo būdai** (t.y. kryptys, paradigmos) skirstomos į dvi dideles šakas:
  1. **procedūrinis** (procedural) žinių vaizdavimas. Algoritmai ir programos yra šio vaizdavimo pavyzdžiai (pavaizdavimas plačiąja prasme);
  2. **deklaratyvus** (declarative) žinių vaizdavimas. Labai apibendrintai ir negriežtai apibūdinsime kaip vaizdavimą duomenimis.

## 8. Loginis išvedimas (Chapter 7)

- Paprastos loginės išvados yra išreikštos sakinių kombinacijomis kaip "ne", "ir", "arba", "jeigu - tada". Tokiais deriniais apibūdinamos situacijos, nurodo kokias savybes tos situacijos turi arba neturi: kažkas yra "ne tai, bet tai".
- (F for “fish”, M for “meat”, V for “vegetarian”)
- F or V or M, not M, not F =⇒ V
- Jeigu iš 3 galimų variantų atkrenta 2, lieka 1variantas kuris loginio išvedimo principu yra teisingas.
- Sudoku veikia tuo pačiu principu. (3x3)
- **Modelis**
  - Sąvoka modelis gali būti taikoma aprašant pasaulius ir modelis suprantamas kaip formalus pasaulio vaizdavimas, kuriame gali būti nustatyta tiesa.
  - Sakome m yra modelis  sakinio α jei α tiesa modelyje m
  - M(α) α modelių aibė
  - Tada KB ╞ α jei  M(KB) ⊆ M(α)

## 9. Predikatų (Pirmos-Eilės) Logika (Chapter 8)

- **Subjektais** gali būti bet kurie objektai, kurie yra užrašomi kaip kintamieji.
- **Predikatas** - sakinys su kintamaisiais, kuris gali būti teisingas arba klaidingas priklausomai nuo kintamųjų reikšmių.
- Predikatas tampa **teiginiu**, kai kintamiesiems priskiriamos reikšmės.
- Veiksmai:
  - `⇒` - Implikacija
  - `⇔` - Ekvivalencija
  - `∧` arba `&` - Konjunkcija (teisingas tik jei abu teisingi)
  - `∨` - Disjunkcija (teisingas jei bent vienas teisingas)
  - `∀` - Kiekvienas
  - `∃` - Yra toks - bent vienas (egzistuoja) - pirmos eilės logika

## 10. Praktiniai pavyzdžiai:  WordNet ; DBpedia ; SUMO/MILO ; Wolfram Alpha’s (Skaidrės ir WEB)

- ...

## 11. Planavimo uždavinių kalbos (Chapter 10)

### Strip

- Strip būsenos vaizduojamos predikatų logikos sakiniais. Tikslas Strip kalboje nusakomas kaip dalinai aprašyta būsena kurią nusakantys kintamieji įgauna teigiamas reikšmes „true“. Laikome kad būsena **„S“** tenkina tikslo **„G“** sąlygą jei **„S“** turi savyje visus kitamuosius esančius **„G“**. Strip nenagrinėja laiko kaip atskiro faktoriaus  jis yra neapibrėžtas. Strip kalboje laikoma, kad veikmai įvyksta akimirksniu ir kad veiksmų seka eina vienas paskui kitą be jokių pauzių
- Veiksmus strip kalboje nusako:
  1. Pavadinimai ir parametrai.
  1. Salygą išreikšta loginiu sakiniu
  1. Efektas nusakytas loginiu sakiniu ir kuris parodo kaip pasikeičia sistemos būsena, kai veiksmas atliktas. Jis susideda iš dviejų dalių
      1. Papildomi sakiniai kurie pridedami
      1. Sąrašas sakinių, kurie išmetami

### CPM

- Darbas gali susidėti iš keleto veiksmų, kurių kievkeinas gali turėti apibrėžtus laiko intervalus ir reikalauti ir tam tikrų resursų. Paieškos tisklas gali būti formuluojamas kaip uždavinys minimizuoti laiko sąnaudas. Tam tikslui dažnai nauduojamas kritinio kelio metodas **(CPM)** . Metodo esmę sudaro Tinklinis grafikas, kur viršūnes atitinka įvykiai, o lankai – darbai. CPM reikalauja, kad kiekvienam projekto darbui būtų numatyta trukmė
  - **Pirmas etapas**. Tinklas analizuojamas praėjimu į priekį - **tiesioginis praėjimas**. Skaičiavimai prasideda nuo pradžios viršūnės (pradinio įvykio) ir tęsiasi tol kol bus pasiekta pabaigos viršūnė (galutinis įvykis). Apskaičiuojamos anksčiausios visu įvykių datos
  - **Antro etapo** metu tinklas analizuojamas praėjimu atgal - **atvirkštinis praėjimas**. Skaičiavimai prasideda nuo pabaigos viršūnės ir tęsiasi tol kol bus pasiekta pradžios viršūnė. Apskaičiuojamos vėliausios įvykių datos ir **kritinis kelias**.

## 12. AI uždaviniai ir neapibrėžtumas (Chapter 13)

- Sprendimas yra **racionalus**, jei jis duoda didžiausią tikėtiną naudingumo vidurkį iš visų galimų veiksmų.
- **Uncertainty** comes from:
  - partial observability,
  - nondeterminism (even for the same input, can exhibit different behaviors on different runs),
  - a combination of the two
- A fully specified **probability model** associates a numerical probability `P(ω)` with each possible world. The basic axioms of probability theory say that every possible world has a probability between 0 and 1 and that the total probability of the set of possible worlds is 1.

## 13. Bajeso tinklo semantika (Chapter 14)

- **Bajeso tinklai** yra tikimybinių santykių tarp atsitiktinių kintamųjų naudojant salygines tikimybes grafinis vaizdavimas. Sujungiama grafų teorija ir tikimybių teorija. Svarbiausia Bajeso tinklų funkcija yra: pasitelkiant matematinės struktūros modeliavimą, sudėtingi santykiai tarp atsitiktinių kintamųjų gaunami išlaikant gana paprastą vizualizaciją.
- Žingsniai:
  1. Nustatyti skaičių kintamųjų turinčių įtaką srityje.
  1. Nustatyti tiesioginę įtaką, ryšius tarp kintamųjų srityje.
  1. Nustatyti sąlygines tikimybes, atsižvelgiant į Bajeso tinklų struktūrą.
- **Netinka**, kai duomenys yra visiškai atsititiniai. Nėra pakankamas, kadangi praleidžiami svarbūs ryšiai. Daug skaičiavimų. 
- **Priežastiniai Bajeso tinklai** – tinklų pagalba sąryšis tarp kintamųjų aprašomas naudojant koreliaciją ir asociaciją tarp kintamųjų. Tai reiškia pradiniai kintamieji yra įtakojami naujų kintamųjų atsiradimo. 

## 14. Markovo stacionarūs procesai (Chapter 15)

- Visą laiką nagrinėjome tikimybinius modelius, kai būsenų reikšmės nekinta, todėl buvo galima nagrinėti visas būsenas ir remtis nekintamais pradiniais duomenimis.
- Dabar nagrinėsime kitokį atvejį - **Būsenos kinta laike**. Kiekvienu laiko momentu t, yra vis kitokia būsenos reikšmė X. (X gali būti rinkinys reikšmių). Taip pat laike kinta ir žinomi duomenys ("Evidence", **E**).
- Problemą nagrinėsime skirstydami procesus į laiko momentus t. Patogumo dėlei, laikysime, kad tarp kiekvieno t yra fiksuotas atstumas, t.y., laiko momentai eina tolygiai.
- Žymėjimai:
  - **X<sub>t</sub>** - laiko momentu t esančių būsenos kintamųjų rinkinys (nežinomos reikšmės)
  - **a:b** - seka nuo a iki b
  - **X<sub>a:b</sub>** - X reikšmės nuo X<sub>a</sub> iki X<sub>b</sub>
  - **P(X<sub>t</sub> \| X<sub>0:t-1</sub>)** - Sąlyginė tikimybė (t.y., tikimybė, kad reikšmė bus X<sub>t</sub> priklauso nuo reikšmių X<sub>0:t-1</sub>)
- **Markovo prielaida** - "ateities būsena priklauso tik nuo **baigtinio ir nekintančio** skaičiaus ankstesnių būsenų"
- **Markovo procesai** - Markovo prielaidą tenkinantys procesai
- Yra skirtingų rūšių Markovo procesų:
  - **Pirmos eilės** Markovo procesai - ateities būsena priklauso tik nuo dabartinės būsenos, bet ne nuo kitų ankstesnių, t.y., **P(X<sub>t</sub> \| X<sub>t-1</sub>)**
- Netgi ir nagrinėjant pirmos eilės procesus, turime problemą: laiko momentų t gali būti be galo daug, todėl ir X reikšmių gali būti begalybė begalybių (šito geriau nerašyti egzamine ant lapo). Kad išvengtume šios problemos, darysime prielaidą, kad problema gali būti nusakoma stacionariu procesu.
- **Stacionarus procesas** - procesas, kuris keičia būsenos reikšmes pagal iš anksto nustatytą ir žinomą dėsnį. Tai reiškia, kad P(X<sub>t</sub> \| X<sub>t-1</sub>) bus lygiai tokia pati visiems t, todėl užtenka sumodeliuoti vieną salyginės tikimybės reikšmių lentelę.

## 15. Mokymasis naudojant stebėjimus (Chapter 18)

- Mokymosi tipai:
  - Mokymasis su mokytoju
  - Autonominis
  - Reaktyvus aplinkai
- **Indukcinis mokymasis** - kai iš turimų duomenų (input-output) yra daromos prielaidos
- **Asociacijos taisyklės** - tai rule based machine learningo metodas, naudojamas ryšių radimui tarp kintamųjų, kai turime labai daug duomenų. Pagrindinė paskirtis- rasti „stiprias“ taisykles, naudojant tam tikrus „įdomumo“ matavimus.
- **Taisyklės metrikos**:
  - Support: LHS U RHS (skaičiuoja iš visos aibės)
  - Confidence: tikimybė, kad LHS -> RHS (skaičiuoja tik iš tos aibės dalies, kuriai priklauso)
- Taip galimas mokymasis paaiškinant- tai kai turimus šablonus modifikuojam ir kai kuriuos objektus keičiam į kintamuosius.

## 16. Apriori Algoritmas (Skaidrės)

- **Apriori algoritmas** identifikuoja skirtingų itemų dažnį duombazėje ir plečia ratą į kurį jie patenka, tol, kol jie pakankamai dažnai kartojasi duomenų bazėje. (Kaip suprantu, tai tiesiog yra augančios aibės, apie kurias renkami duomenys ir daromos išvados). Šis algoritmas naudoja mokymąsi pagal asociacijos taisykles.
- Fiksuojame minimalų būtiną skaičių su kuriuo taisyklė turi pasirodyti duomenų bazėje
- Didiname po vieną atributą kiekvieną kartą ir surenkame rinkinius kurie tenkina užduotą dažnumo parametrą

## 17. Sprendimų medžiai (Chapter 18)

- **Sprendimų medį** galima aprašyti kaip funkciją, kuri ima pirminius duomenis ir grąžina sprendimą, padarytą tų duomenų pagrindu. Kaip galime spėti iš pavadinimo, sprendimų priėmimo algoritmas grafiškai gali būti pavaizduotas kaip medžio struktūra, medžio mazguose užrašant logines sąlygas, o sprendimus pavaizduojant kaip medžio šakas

## 19. Neuroniniai tinklai (Chapter 18.7)

- ...

## 18. Natūralios kalbos skaičiavimai (Chapter 22 ir 23)

- Natūralios kalbos **trūkumai**:
  - Formal languages, such as the programming languages Java or Python, have **precisely defined language models**.
  - Natural languages, such as English or Spanish, **cannot be characterized** as a definitive set of sentences.
  - That is, rather than asking if a string of words is or is not a member of the set defining the language, we instead ask for P(S =words )
  - Natural languages are also **ambiguous** (nevienareiksmes)
  - Finally, natural languages are difficult to deal with because they are **very large**, and **constantly changing**.
- **Language models**: models that predict the probability distribution of language expressions.
- It is more fruitful to define a natural language model as a **probability distribution over sentences** rather than a definitive set
- n-gram - n ilgio simbolių seka
- n-gram modelis - apibrėžtas kaip n-1 lygmens Markovo grandinė, kur P(c<sub>1:N</sub>) = ∏ P(c<sub>i</sub> \| c<sub>i-2:i-1</sub>)