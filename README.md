# UPR-League_of_Legends_ELO_rating
Napište program, který bude počítat rank, divizi a různé další statistiky hráčů hry **League of Legends (LoL)** podle záznamů LoL her. Tyto statistiky budou vypsány ve formě nějakého grafického výstupu (HTML stránka, SVG graf, …).


## Vstup programu:

  Program bude povinně akceptovat tři argumenty z příkazové řádky.

      První argument bude obsahovat cestu k souboru se záznamy LoL her.
      Druhý argument bude obsahovat cestu k souboru s přezdívkami hráčů.
      Třetí argument bude obsahovat cestu k výstupnímu souboru.


## Načtení dat:

  Nejprve načtěte obsah souboru se záznamy her. V souboru bude několik záznamů o jednotlivých LoL hrách, které proběhly po sobě ve stejném pořadí, v jakém jsou v souboru. Každý záznam bude mít následující strukturu:

    Na prvním řádku záznamu musí být řetězec match.
    Na druhém řádku budou ID hráčů, kteří hráli za červený tým (počet hráčů musí být 3).
    Na dalším řádku budou postupně hodnoty zabití (K), asistencí (A) a smrtí (D) pro každého hráče. Tyto tři hodnoty budou odděleny středníkem, hodnoty pro jednotlivé hráče budou odděleny čárkou.
    Na dalších dvou řádcích budou obdobné informace pro modrý tým.
    Na posledním řádku záznamu bude výsledek záznamu.
        Pokud zde bude řetězec "red", tak vyhrál červený tým.
        Pokud zde bude řetězec "blue", tak vyhrál modrý tým.

  Ukázkový obsah souboru se záznamy:

      match
      1,2,3
      10;3;2,8;2;0,2;5;4
      8,4,9
      1;4;10,5;1;2,0;2;8
      red
      match
      2,1,8
      5;2;4,8;4;4,4;4;3
      13,22,10
      4;4;10,5;1;4,2;2;3
      blue

  Dále načtěte soubor s názvy hráčů. Na každém řádku souboru bude dvojice oddělená čárkou. Prvním členem dvojice bude **ID hráče** a druhým členem jeho **přezdívka**.

  Ukázkový obsah souboru s názvy hráčů:
  
      1,darksider
      2,yasuo4life
      4,heimerdanger
      
  Obsah souboru použijte pro spárování ID hráčů s jejich přezdívkou při výpisu statistiky.


Pokud vstupní data v jakémkoliv ze vstupních souborů nebudou odpovídat zadanému formátu, vypište chybu a ukončete program. Stejně tak zkontrolujte, jestli vstupní data dávají smysl (i kdyby byly ve správném formátu). Například nedává smysl, aby v rámci jednoho zápasu hrál hráč se stejným ID za více šampionů.


## Výpočet statistiky:

  Vypočtěte tzv. ELO rating pro každého hráče. Postupně projděte všechny zápasy jeden po druhým a aktualizujte hodnoty ratingu pro jednotlivé hráče. Každému hráči po každém jeho zápasu aktualizujte jeho rating pomocí následujícího vzorce:

    ra // rating hráče
    rb // rating soupeře, vypočítejte ho jako průměrnou hodnotu ratingu soupeřova týmu
    ea = 1 / (1 + 10^((rb - ra) / 400))  // znak `^` značí mocninu.
    k = 30
    sa // 1 pokud hráčův tým vyhrál, 0, pokud prohrál
    novy_rating = ra + k * (sa - ea)
    
  Poprvé, když v seznamu zápasů narazíte na nějakého hráče, inicializujte jeho rating na hodnotu 1000. Při zpracování zápasu použijte veškeré hodnoty ratingu pro všechny hráče takové, jaké byly před tímto zápasem.

  Podle výsledného ratingu každého hráče zařaďte do jedné z následujících divizí:
  
    Bronze - rating mezi 0 a 1149
    Silver - rating mezi 1150 a 1499
    Gold - rating mezi 1500 a 1849
    Platinum - rating mezi 1850 a 2199
    Diamond - rating 2200 a výše

  Dále vypočtěte nějaké zajímavé statistiky pro jednotlivé hráče, například počet výher/proher, poměr zabití a smrtí, počet absolvovaných zápasů, nejčastější barva týmu atd.
  
  
## Zápis výsledku:

  Vytvořte výstupní soubor, který bude obsahovat vypočtené statistiky jednotlivých hráčů a jejich rating a divizi v přehledné formě. Můžete vytvořit například **HTML tabulku**, **SVG graf** nebo **DOT graf**. Na podobě výstupu se domluvte se svým cvičícím.
  
  
## Poznámky k řešení:
  
  Ošetřte v programu chyby, které můžou nastat, např. špatné vstupní parametry. V případě chyby vypište chybovou hlášku a ukončete program s chybovým kódem *1*.

  Projekt rozumně rozdělte do více .c/.h souborů a vytvořte k němu **bash skript**, **Makefile** nebo **CMakeLists.txt** soubor, aby šel projekt přeložit i na jiném počítači (viz automatizace překladu).

  Vytvořte jednoduchý **README** soubor, který bude popisovat, jak program funguje a jak ho přeložit.

  Při vývoji používejte **Address sanitizer!** Velmi vám to usnadní detekci paměťových chyb. Odevzdaný program nesmí při použití Address sanitizeru vyvolat žádné paměťové chyby.
