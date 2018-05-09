# Interneto technologijos

## T1. Žiniatinklis

- 1980 m. naudoti uždari kompiuterių tinklai, grįsti **packet switching** technologija - žinutė suskaidoma ir siunčiama dalimis efektyviausiu maršrutu, o atkeliavusios dalys vėl sujungiamos.
- 1982 JAV saugumo departamentas paskelbia TCP/IP (Internet Protocol Suite) - tai interneto pradžia
  - Transmission Control Protocol (TCP) and the Internet Protocol (IP).
  - The Internet protocol suite provides end-to-end data communication specifying how data should be packetized, addressed, transmitted, routed, and received. 
- 1985-ais sukuriamas **NSFNET** paremtas TCP/IP technologija. Jis išauga iki 100 000 kompiuterių taip padėdamas TCP/IP protokolams išpopuliarėti.
- 1991-ais pašalinami NSFNET apribojimai. Konkurentai netenka turėto pranašumo. Internetas tampa vieša erdve

---

- **Sir Tim Berners-Lee** - CERN programuotojas, sukūrė HTMl, URI/URL ir http
- **1991-08-06** paskelbiamas pirmasis web saitas pasaulyje, CERN tinklalapis
- **1994** jis įkuria W3C

---

- `http` - protocol
- `://`
- `www` - subdomain (dalis *resource name*)
- `.` (dalis *resource name*)
- `google` - domain name (dalis *resource name*)
- `.` (dalis *resource name*)
- `com` - top-level domain (dalis *resource name*)
- `/`
- `index.html` - file path

---

- **Web sistemos** - Sistemos, kurios naudoja interneto ir web technologijas paslaugoms ar informacijai teikti
- **Prievado** reikšmė apribota nuo 0 iki 65535 (2<sup>16</sup> - 1)
- Gerai žinomi prievadai (well-known ports) yra nuo 0 iki 1023. Jų naudoti savo kuriamam aplikacijos sluoksnio protokolui nepatartina.
  - 25 - Simple Mail Transfer Protocol (SMTP) - el. laiškams siųsti
  - 80 - Hypertext Transfer Protocol (HTTP) - web naršymui
  - 110 - Post Office Protocol Vesion 3 (POP3) - el. laiškams gauti
- Savo kuriamam aplikacijos sluoksnio protokolui patartina naudoti prievadus nuo 1024 iki 65535
  - 5432 - standartinis PostgreSQL duomenų bazės prievadas
  - 6881–6887 - dažnai naudojamas BitTorrent prievadų intervalas
  - 27017 - standartinis MongoDB prievadas

## T2. HTTP protokolas

- **Internetas** - susijungusių kompiuterių tinklų globali sistema
- **Žiniatinklis (WWW arba Web)** - globalus rinkinys dokumentų ir kitų resursų sujungtų nuorodomis (hyper links) ir uniforminiais resursų identifikatoriais (uniform resource identifiers (URIs))
- **TCP/IP** modelis:
  1. **Application layer**  naudoja žemiau esančių sluoksnių protokolus (dažniausiai TCP, UDP ir IP) sistemos duomenims perduoti 
  2. Transport layer
  3. Internet layer
  4. Network access layer
- `scheme:[//[user:password@]host[:port]][/]path[?query][#fragment]`
- **Domain Name System** Ieškomam srities vardui (domain name) gražina IP adresą
  - Naudoja UDP Transporto sluoksnio protokolą (prievadas 53)
- **HTTP** - Hiperteksto perdavimo protokolas (Hypertext Transfer Protocol)
  - **Request**
  ```
  GET http://localhost/api/ping HTTP/1.1↩
  Host: localhost↩
  Connection: keep-alive↩
  User-Agent: Chrome/55.0.2883.87↩
  Accept: */*↩
  Referer: http://localhost/app/index.html↩
  Accept-Encoding: gzip, deflate, sdch, br↩
  Accept-Language: en-US,en;q=0.8,lt;q=0.6↩
  If-None-Match: W/"12-rsPRhBP8aOVLxyWjUzLLlQ"↩
  ```
  - **Response**
  ```
  HTTP/1.1 200 OK↩
  X-Powered-By: Express↩
  Content-Type: text/plain; charset=utf-8↩
  Content-Length: 19↩
  ETag: W/"4-b9sIeqP7+8uCh6WToJGeYQ"↩
  Date: Tue, 20 Dec 2016 10:23:03 GMT↩
  Connection: keep-alive↩
  ↩
  My response message
  ```

---

- `GET` - web resursui gauti (užklausa kūno neturi)
- `POST` - duomenims į serverį nusiųsti
- `OPTIONS` - informacija apie komunikacijų opcijas
- `HEAD` - tas pats kaip GET tik be kūno (body) atsakyme
- `PUT` - resursui serveryje išsaugoti arba atnaujinti
- `DELETE` - resursui serveryje pašalinti (užklausa kūno neturi)
- `TRACE` - sužinoti, ką gavo serveris (kai siunčiama per tarpininkus)
- `CONNECT` - naudojamas su proksiu (proxy)
- `PATCH` - atnaujinti resurso dalį (papildomas metodas apibrėžtas atskiroje specifikacijoje)

---

- Metodai, kurie nekeičia serverio būsenos, tik gražina duomenis yra saugūs (**safe**):
  - GET
  - HEAD
  - OPTIONS
  - TRACE
- Metodai, kurie keičia serverio būseną, pvz.:
  - POST
  - PUT
  - DELETE
  - PATCH
- Metodai kurių rezultatas kviečiant daug kartų yra tas pats kaip kviečiant vieną kartą yra silpni (**idempotent**):
  - GET
  - HEAD
  - PUT
  - DELETE
  - OPTIONS
  - TRACE
- Metodas, kurio kiekvienas kvietimas turi unikalų rezultatą, pvz.:
  - POST
  - PATCH
- Užklausos **URI formos**:
  - Origin form (kilmės) - naudojama tiesioginėms užklausoms (be tarpininko) `GET /path/save?id=2 HTTP/1.1`
  - Absolute form (absoliuti) - naudojama užklausoms per tarpininką (proxy) `GET http://www.example.com/path/save?id=2 HTTP/1.1`
  - Authority form (įgaliojimų) - naudojama tik su CONNECT užklausa tuneliui sukurti (tunnel):  
  - Asterisk form (asterikso) - naudojama tik su OPTIONS užklausa serverio mastu (palyginus su kitomis užklausomis yra resurso mastu)
- **Būsenos kodai**:
  - `1xx` - Informacinis (Informational): užklausa buvo gauta, tęsiamas apdorojimas
  - `2xx` - Sėkmingas (Successful): užklausa buvo sėkmingai gauta, suprasta ir priimta
    - `200 OK` - užklausa pavyko
    - `201 Created` - užklausa pavyko, buvo sukurtas resursas
    - `202 Accepted` - užklausa pavyko, tačiau dar nebuvo baigtas vykdyti
    - `204 No Content` - užklausa pavyko, tačiau atsakymas yra tuščias
  - `3xx` - Peradresavimas (Redirection): Reikalingas kitas veiksmas norint kad užklausa būtų užbaigta
  - `4xx` - Kliento klaida (Client Error): Užklausa turi klaidų arba negali būti išpildyta
    - `400 Bad Request` - serveris negali apdoroti užklausos dėl jos nevalidumo
    - `403 Forbidden` - užklausa suprasta, tačiau klientui draudžiamas jos vykdymas
    - `404 Not Found` - nerastas užklausiamas resursas
    - `405 Method Not Allowed` - metodas nepalaukomas su nurodomu resursu
    - `408 Request Timeout` - serveris nespėjo sulaukti pilnos užklausos per tam skirtą laiką
  - `5xx` - Serverio klaida (Server Error): Serveriui nepavyko įvykdyti validžios užklausos
    - `500 Internal Server Error` - serveryje įvyko nenumatyta klaida
    - `501 Not Implemented` - serveris dar nepalaiko norimos užklausos
    - `503 Service Unavailable` - nerastas užklausiamas resursas
- HTTP **Header** (Antraštė)
  - Tarp didžiųjų ir mažųjų raidžių nėra skirtumo (case insensitive)
  - `Host` - nurodo domeną, kuriam siunčiama žinutė. **Vienintelė privaloma antraštė!**
  - `Connection` - prisijungimo indikacija (pvz.: keep-alive - likti prisijungus, close - uždaryti)
  - `Content-Type` - kūno duomenų tipas (pvz.: text/html - HTML dokumentas)
  - `Content-Encoding` - kūno duomenų užkodavimas (pvz.: compress - suspaudimas)
  - `Content-Language` - kūno duomenų kalba (pvz.: en-US - Amerikos anglų)
  - `Content-Length` - kūno duomenų ilgis baitais
  - `Transfer-Encoding` - kūno duomenų užkodavimas (pvz.: chunked - transportavimas kūną suskaidžius į dalis)
- **HTTP 1.1**:
  - Išliekantis prisijungimas (Persistent connection)
    - vieno prisijungimo panaudojimas daugiau nei vienai HTTP užklausai vykdyti
  - Lygiagretinimas (Pipelining)
    - daugiau nei vienos užklausos siuntimas nelaukiant atsakymo
    - SVARBU! Dėl eilės blokavimo ir kitų problemų ši HTTP 1.1 savybė yra praktiškai nenaudojama (žiūrėti HTTP 2 protokolo multipleksavimo savybę)
  - Problemos:
    - **Latencija** (latency) - delsimas iki kol pradedami siųsti duomenys
    - **Round-trip delay time** (RTT) - laikas reikalingas duomenims nusiųsti ir patvirtinti, kad duomenys buvo sėkmingai nusiųsti
- **HTTP 2** - Binarinis protokolas (Binary)
  - Multipleksavimas (Multiplexing)
    - Keli srautai (streams) vienoje jungtyje (connection)
    - Taigi užtenka vienos jungties (connection) domenui (domain)
  - Serverio push’as (Server push)
    - Serveris gali pasiųsti porą atsakymų
      - Prašant HTML failo, kartu yra paduodami ir susiję stiliai bei paveiksliukai
    - Klientas gali atsisakyti priimti papildomus resursus (RST STREAM)
      - Tarkime resursai jau egzistuoja naršyklės atmintyje (cache)

## T3. JavaScript pagrindai

- **Procesas** (Process) - operacinės sistemos dalis apibūdinanti leidžiamos programos resursus (unit of resources)
- **Gija** (Thread) - proceso dalis, kuri planuoja ir leidžia programos kodą (unit of scheduling and execution)
- Gijų problemos:
  - Shared memory access
  - Race condition
- **Įvykiais-varomas (event-driven) programavimas** - programavimo paradigma, kurios metu programos vykdymo seka yra nusprendžiama įvykių
- Non-blocking Input/Output (**NIO**):
  - Naudojant NIO, gijų valdymu pasirūpina NIO karkasas, todėl programuotojui atrodo, kad jo programa veikia paraleliai, bet nereikia rūpintis, kad daugiau nei viena gija vienu metu leis tą pačią kodo vietą
    - IO atveju, norint atlikti veiksmus paraleliai, reikia patiems pasirūpinti gijų valdymu
  - Naudojant NIO, galima atlikti daugiau veiksmų, nes gijos panaudojamos tik įvesčiai/išvesčiai: reikia mažiau gijų: naudojama mažiau atminties
    - IO atveju gijos naudojamos ne tik su įvestimi/išvestimi (IO) susijusiam kodui leisti
  - Naudojant IO, paleidus vieną programą, galimą išnaudoti visus procesorius (cores), nes skirtingos gijos gali naudoti skirtingus procesorius
    - NIO atveju reiktų paleisti tiek programų, kiek kompiuteryje yra procesorių (cores), o užklausoms į programas balansuoti reikalinga dar viena programa (load balancing)
- **JS naudoja NIO**
- **JS engines:**
  - V8 - sukompiliuoja JS kodą į mašininį kodą ir tada leidžia
  - SpiderMonkey (Firefox) - sukompiliuoja JS kodą į baitų kodą (byte code) ir tada jį interpretuoja
  - Rhino / Nashorn (Java) - sukompiliuoja JS kodą į Java baitų kodą (byte code) ir tada leidžia su Java Virtualia Mašina (JVM)

---

- Number - apvalinimas pagal IEEE-764 standartą
- String - tarp “ arba ‘ arba ` kabučių (UTF-16)
- Boolean - true arba false
- Null - tik null
  - rekomenduojama naudoti taikomajame kode
- Undefined - tik undefined
  - rekomenduojama nenaudoti taikomajame kode
- Symbol
- Object
- Array (masyvas) - specialus objekto tipas
- Spread/Rest operator
- Destructuring
- Modules:
  - **Core** - Neprasideda / ./ arba ../ `require(‘fs’)`
  - **File** - Prasideda / ./ arba ../ `require(‘./module’)`
  - **npm** - Nėra core tipas ir neprasideda / ./ arba ../ `require(‘express’)`

---

- Objektinė kalba
  - Enkapsuliacija (Encapsulation)
  - Paveldėjimas (Inheritence)
  - Virtualūs metodai (Virtual methods)
- Funkcinė kalba
  - Grynos funkcijos (Pure functions)
  - Nikintamumas (Immutablity)
  - Neturinti būsenos (Stateless)
  - Deklaravyti (Declarative)
  - Aukštesnės paskirties funkcijos (Higher order functions)
  - Rekursija (Recursion)

## T4. Web backend'o pagrindai

- **SOAP** - Simple Object Access Protocol
  - Lėtas XML nagrinėjimas (parsing)
  - Žinutėse daugiažodžiaujama (verbose)
  - Juk skirta aparatams, o ne žmonėms
  - Praktiškai naudojamas tik POST HTTP metodas
  - Praktiškai nenaudojamas URI
  - Praktiškai nenaudojamos HTTP antraštės (headers)
- **REST** - Representational state transfer (REST) arba RESTful Web services
  - JSON
  - Skirtingas HTTP metodas - skirtingas veiksmas su resursu
  - Resursas yra daiktavardis
  - Organizuotas REST yra vadinamas REST API (App programming interface)

---

- **REST** response bodies:
  - 2xx - viskas gerai:
    - POST /<resursas> atveju grąžinti sukurtą resursą
    - GET /<resursas> atveju grąžinti resursų sąrašą (pvz.: JSON array)
    - GET /<resursas>/:id atveju grąžinti prašomą resursą pagal jo identifikatorių
    - PUT /<resursas>/:id arba PATCH /<resursas>/id atveju grąžinti pakeistą resursą
    - DELETE /<resursas>/:id atveju gražinti ištrintą resursą
  - 3xx - resursas buvo perkeltas
  - 4xx - kliento klaida, grąžinti klaidos tekstą
  - 5xx - serverio klaida, grąžinti klaidos tekstą
- **REST** headers:
  - Puslapiavimas (pagination):
    - start: 30 grąžinti nuo 30 resurso
    - count: 15 gražinti 15 resursų
  - Autentifikacija (authentification):
    - token: A2FCD65BC88 pateikti prisijungimo metu išduotą žetoną (token)
  - Filtravimas
    - filter: name=Mykolas&age=26 pateikti filtro sąlygas
- **Versijavimas**
  - Sukurtas REST API yra atnaujinamas
    - Galbūt keičiasi užklausos parametrai
    - Galbūt keičiasi atsakymo struktūra
  - Kiekvienam API ar servisui yra nurodoma versija
    - Vietoje https://api.com/api/user
    - https://api.com/ 1/api/user
    - https://api.com/api/ 1/user
- **GraphQL** is a query language for APIs and a runtime for fulfilling those queries with your existing data. GraphQL provides a complete and understandable description of the data in your API, gives clients the power to ask for exactly what they need and nothing more, makes it easier to evolve APIs over time, and enables powerful developer tools.

## T5. Web frontend'o pagrindai

- AJAX - Asynchronous JavaScript and XML
- **Array**:
  - `concat()` - Joins two or more arrays, and returns a copy of the joined arrays
  - `copyWithin()` - Copies array elements within the array, to and from specified positions
  - `entries()` - Returns a key/value pair Array Iteration Object
  - `every()` - Checks if every element in an array pass a test
  - `fill()` - Fill the elements in an array with a static value
  - `filter()` - Creates a new array with every element in an array that pass a test
  - `find()` - Returns the value of the first element in an array that pass a test
  - `findIndex()` - Returns the index of the first element in an array that pass a test
  - `forEach()` - Calls a function for each array element
  - `from()` - Creates an array from an object
  - `includes()` - Check if an array contains the specified element
  - `indexOf()` - Search the array for an element and returns its position
  - `isArray()` - Checks whether an object is an array
  - `join()` - Joins all elements of an array into a string
  - `keys()` - Returns a Array Iteration Object, containing the keys of the original array
  - `lastIndexOf()` - Search the array for an element, starting at the end, and returns its position
  - `map()` - Creates a new array with the result of calling a function for each array element
  - `pop()` - Removes the last element of an array, and returns that element
  - `push()` - Adds new elements to the end of an array, and returns the new length
  - `reduce()` - Reduce the values of an array to a single value (going left-to-right)
  - `reduceRight()` - Reduce the values of an array to a single value (going right-to-left)
  - `reverse()` - Reverses the order of the elements in an array
  - `shift()` - Removes the first element of an array, and returns that element
  - `slice()` - Selects a part of an array, and returns the new array
  - `some()` - Checks if any of the elements in an array pass a test
  - `sort()` - Sorts the elements of an array
  - `splice()` - Adds/Removes elements from an array
  - `toString()` - Converts an array to a string, and returns the result
  - `unshift()` - Adds new elements to the beginning of an array, and returns the new length
  - `valueOf()` - Returns the primitive value of an array
- **DOM** - Document Object Model (document)

## T6. Modernus web sistemos frontend'as

- **Data binding**:
  - One-way
  - Two-way
    - Sunku valdyti ryšius tarp kelių dviejų pusių surišimų
    - Sunku taisyti klaidas, kuomet kažkas nesinchronizuojama
    - Sunku taisyti klaidas, kuomet kažkas sinchronizuojasi amžinai (“užsiciklina”)
- **React** `input` binding: `value=...` ir `onChange={ () => ... }`
- DOM pakeitimai yra labai lėti, todėl dažnai reikia galvoti kaip padaryti kuo mažiau pakeitimų DOM’e, kad pasiektume tą patį rezultatą greičiau.
  - React karkasas DOM atnaujina už mus per taip vadinamą “virtualų DOM”
  - Nors mums atrodo, kad kode manipuliuojame DOM’u, tačiau tai darome su “virtualiu DOM” - tikro DOM atspindys sudarytas iš React elementų
  - React karkasas automatiškai sinchronizuoja pakeitimus tarp “virtualaus DOM” ir tikrojo DOM efektyviausiu būdu
  - Pvz.: jei keičiame sąrašą išimdami iš jo senus elementus ir juos pakeisdami naujais - React panaudoja trinamus DOM elementus jiems suteikdamas naujų elementų reikšmes, t.y. stengiasi trinti ir kurti kuo mažiau naujų elementų
- **React component lifecycle**:
  - mount:
    - constructor()
    - componentWillMount()
    - render()
    - componentDidMount()
  - update - Atnaujinimas įvyksta kai: paduodamas bet vienas komponento “props”; pakeičiamas komponento “state”
    - componentWillReceiveProps()
    - shouldComponentUpdate()
    - render()
    - componentDidUpdate()
  - unmount:
    - componentWillUnmount()

## T7. Web sistemos duomenų bazė

- **ACID**
  - Atomicity - įvykdžius tranzakciją arba atliekami VISI pakeitimai arba NEI VIENAS
  - Consistency - kiekviena tranzakcija DB perveda iš vienos validžios būsenos į kitą
  - Isolation - vykdant tranzakciją atrodo, kad vykdoma tik ji viena
  - Durability - įvykdžius tranzakciją ji pasilieka įvykdyta, nepaisant dingusios elektros, PĮ užstrigimo ir t.t.
- **NoSQL** - non SQL / non relational / not only SQL
  - Kitokia duomenų schema (arba jos nebuvimas):
    - Stulpeliai (column) - ne eilutemės kaip įprasta - patogu dirbti su stulpelio duomenimis
    - Dokumentai (document) - medžio (tree) struktūra - patogu dirbti su hierarchiniais duomenimis
    - Raktas-reikšmė (key-value) - hash tipo duomenys (panašu į JavaScript objektą)
    - Grafai (graph) - duomenys: briaunos ir viršūnės (facebook’as)
  - Dažniausia naudojama:
    - Dideliems duomenų kiekiams saugoti (lengva plėsti (scale))
    - Su realaus laiko sistemomis (greita ištraukti duomenis)
- **Redis**:
  - Raktas-reikšmė (key-value) struktūra
  - Naudojama kaip DB, cache arba žinučių brokeris (message broker)
- **MongoDB**: Saugomi dokumentai. JSON (BSON). Skriptai rašomi JavaScript kalba
  - **Paskirstyta DB** - duomenys laikomi daugiau nei viename mazge (node)
    - Replikavimas (Replication) - duomenys kopijuojami tarp mazgų
    - Padalinimas (Sharding) - skirtingi duomenų rėžiai skirtinguose mazguose
  - **Galiausia darna (eventual consistency)** - po pakeitimo galiausiai duomenys visuose mazguose bus darnūs (tokie kokie ir turi būti po įvykusio pakeitimo)
  - **Mongoose** - ODM

## T8. Web sistemos saugumas

- **Simetrinė kriptavimo sistema** - Šifruojama ir iššifruojama naudojant tą patį raktą
- **AES** - simetrinė kriptavimo sistema:
  - Raktas yra 128, 192 arba 256 bitų ilgio
  - Šifruojama 128, 192 arba 256 bitų ilgio blokais
  - Duomenys suskaitomi į atitinkamo dydžio blokus
  - 10 iki 14 šifravimo iteracijų (priklausomai nuo rakto ilgio)
- Simetrinės kriptavimo sistemos neužtenka
  - Galima saugiai perdavinėti šifruotus duomenis
  - Iššifruoti duomenims reikalingas raktas
  - Raktą reikia saugiai perduoti gavėjui
  - Reikalingas būdas saugiai perduoti raktą
- **Asimetrinė kriptavimo sistema** - Šifruojama vienu raktu, o iššifruojama kitu raktu
- **RSA** - viešojo rakto kriptavimo sistema

---

- **Cookies**: 
  - Turi formatą: raktas=reikšmė (key=value)
  - Reikšmė užkoduojama Base64 formatu
    - Pvz.: Set-Cookie: token=Rg3vHJZnehYLjVg7qi3bZjzg
  - Naršyklė sausainiukus (cookies) išsaugo atmintyje
  - Sausainiukus naršyklė automatiškai įkelia į užklausos antraštę
    - Jei užklausa vykdoma į tą patį domena (domain) ir/arba kelią (path)
    - Pvz.: jei sausainiukas buvo gautas iš example.com domeno, tuomet jei vykdoma užklausa į test.tt domeną - sausainiukas nebus įkeltas į antraštę, jei į example.com - bus
  - Gali turėti galiojimo laiką (expiration time), po kurio yra automatiškai pašalinami iš naršyklės
- **Passport + Express + JWT**

## T9. Web sistemos naudotojo patirtis

- ...
