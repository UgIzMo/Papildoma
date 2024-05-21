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


