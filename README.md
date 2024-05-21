# Papildoma

Papildoma užduotis egzamino praktinei daliai.

Turime programą, kuri nuskaito vartotojo failą ir suskaičiuoja pasikartojančius žodžius bei atranda tekste esančius internetinių svetainių adresus. 
Rezultatai atpausdinami į atskirą failą lentelės pavidalu.

# Programos veikimas

1. Paleidus programą į terminalą išspausdinami programos kataloge esantys `.txt` failai ir vartotojas prašomas įvesti norimo nuskaityti failo pavadinimą.
2. Jei vartotojas pavadinimo nenurodo, programa nuskaito numatytąjį `text.txt` failą.
3. Nepavykus atidaryti nurodyto failo, vartotojui nurodoma įvesti kito failo pavadinimą.
4. Kiekviena teksto eilutė yra skaitoma pažodžiui:
    - Pirmiausiai programa patikrina ar aptiktas žodis nėra internetinės svetainės adresas.
    - Jei yra, jį prideda į adresų sąrašą.
    - Jei nėra, žodį "sutvarko": nuima visus neraidinius simbolius ir paverčia mažosiomis raidėmis.
5. Nuskaičius failą bei suskaičiavus žodžių pasikartojimus, rezultatai atspausdinami į numatytąjį `rezultatai.txt` failą:
    - Atspausdinami internetinių svetainių adresai ir jų kiekis.
    - Atspausdinami pasikartojantys žodžiai, jų pasikartojimo kiekis bei eilutės, kuriose galima aptikti pasikartojančius žodžius.

# Projekto struktūra

- `main.cpp`: Pagrindinis programos failas.
- `funkcijos.cpp`: Funkcijų įgyvendinimas.
- `funkcijos.h`: Funkcijų antraštės.
- `mylib.h`: Naudojamų bibliotekų antraštės.
- `Makefile`: Kompiliavimo taisyklės.
- .txt failai

# Regex  naudojimas

Programa naudoja regex šabloną, kuris atpažįsta URL adresus bet kokio formato tekste. 
Šis šablonas yra patikimas ir leidžia efektyviai surasti URL adresus, nepriklausomai nuo jų struktūros ar formatavimo. 
Regex naudojimas gali būti galingas, tačiau kartais gali būti sudėtingas ir reikalaujantis išsamesnio supratimo.

Regex naudojimas yra sėkmingas būdas atpažinti ir išskirti URL adresus iš teksto, leidžiantis efektyviai rasti ir surinkti internetinių svetainių adresus iš bet kokio formato teksto.


# Kaip paleisti kodą?
# Makefile kūrimas
>[!NOTE]
> Makefile buvo sukurtas užtikrinti sėkmingą įvairių failų sąsajos užtikrinimą kode. Toliau bus pateikta instrukcija, kaip sukonfigūruoti ir naudoti Makefile kūrimo priemonę, kad būtų galima paleisti mano kodą.

# Windows
1. Apsilankykite šioje svetainėje: https://sourceforge.net/projects/gnuwin32/files/make/3.81/
2. Atsisiųskite naujausią versiją.
3. Susikonfiguruokite, nusistatykite viską. Yra pateikta gan aiški instrukcija, jei reikia išsamiau galite pasinaudoti video nuoroda: https://www.youtube.com/watch?v=taCJhnBXG_w
4. Susitvarkę tai, grįžtame į savo turimą projektą failų naršyklėje.
5. Nukopijuojame savo projekto kelią su visais failais (ĮSKAITANT MAKEFILE!)
6. Atsidarome CMD (Command Prompt).
7. Įveskite 'cd ' ir įklijuokite kelią. (cd C:\Users\Asus\Desktop\II pusmetis\bandymai\V1.0_galutinis)
8. Tuomet parašome „mingw32-make“
9. O vėliau „programa.exe“

# Išmanusis būdas, kurį atradau pati
1. Atsisiųskite Xcode arba MinGW kompiliatorių.
2. Kai kompiliatorius yra įdiegtas ir sukonfigūruotas. Atidarykite VisualStudio Code (https://code.visualstudio.com/download).
3. Dabar atidarykite projektą.
4. Eikite į 'extensions' skirtuką ir ieškokite "Makefile Tools" By _Microsoft_.
5. Atsisiųskite jį, tada paleiskite VSCode iš naujo, kad jis iš tikrųjų būtų įdiegtas į jūsų IDE.
6. Kai tai padaryta, paspauskite 'extension' kairėje šoninėje juostoje, ir pamatysite 6 skirtingus kelius, kuriuos plėtinys reikalauja.
7. Windows atveju:
Redaguokite "Make" konfigūraciją naudoti mingw32-make.exe.
Redaguokite "Makefile" konfigūraciją ir įklijuokite projekto kelią.
8. Dabar tiesiog paspauskite "Build" mygtuką (viršutinį kairįjį), kuris sukurs projektą.
9. Tada paspauskite "Run code" mygtuką, kuris jį paleis.








