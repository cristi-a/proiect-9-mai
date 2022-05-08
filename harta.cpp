#include <bits/stdc++.h>
using namespace std;

void init();
void displayMap();
void displayAfrica();
void displayAmericaN();
void displayAmericaS();
void displayAsia();
void displayEurope();
void displayAustralia();
void africa();
void americaN();
void americaS();
void asia();
void europe();
void australia();
void displayCountries(int ind);
vector<vector<string>> countries(7);
vector<vector<string>> curiosities(7);
vector<bool> shown(5);
long long surface[7], population[7];
int afisate;

int main () {
    init();
    string temp;
    int cycles = 0;
    while(1) {
        system("cls");
        displayMap(); cout << endl;
        if(cycles) getline(cin,temp);
        string continent; cout << "ce continent doriti sa vizitati? (pentru a iesi tastati exit) "; getline(cin,continent);
        if(continent == "exit") break;
        for(int i=0; i<continent.size(); i++) continent[i] = tolower(continent[i]);
        int ind = 1;
        string con[10] = {"", "africa", "america de nord", "america de sud", "asia", "australia", "europa"};
        while(ind<=7) {
            if(con[ind]==continent) break;
            ind++;
        }
        if(ind>7) {
            cout << "nu exista aceasta optiune :O\n";
            system("pause");
            continue;
        }
        cout << "ati ales continentul " << con[ind] << "\n";
        system("pause");
        afisate = 0;
        for(int i=0; i<5; i++) shown[i] = false;
        if(ind==1) africa();
        else if(ind==2) americaN();
        else if(ind==3) americaS();
        else if(ind==4) asia();
        else if(ind==5) australia();
        else if(ind==6) europe();
        cycles++;
    }
    return 0;
}

void init() {
    //africa
    surface[1] = 30365000;
    population[1] = 1216000000;
    countries[1].push_back("Burundi");
    countries[1].push_back("Comore");
    countries[1].push_back("Dijbouti");
    countries[1].push_back("Eritreea");
    countries[1].push_back("Etiopia");
    countries[1].push_back("Kenya");
    countries[1].push_back("Madagascar");
    countries[1].push_back("Malawi");
    countries[1].push_back("Mauritius");
    countries[1].push_back("Mozambic");
    countries[1].push_back("Rwanda");
    countries[1].push_back("Seychelles");
    countries[1].push_back("Somalia");
    countries[1].push_back("Tanzania");
    countries[1].push_back("Uganda");
    countries[1].push_back("Zambia");
    countries[1].push_back("Angola");
    countries[1].push_back("Camerun");
    countries[1].push_back("Republica Centrafricana");
    countries[1].push_back("Ciad");
    countries[1].push_back("Republica Congo");
    countries[1].push_back("Republica Democrata Congo");
    countries[1].push_back("Gabon");
    countries[1].push_back("Guineea Ecuatoriala");
    countries[1].push_back("Sao Tome si Principe");
    countries[1].push_back("Algeria");
    countries[1].push_back("Egipt");
    countries[1].push_back("Libia");
    countries[1].push_back("Maroc");
    countries[1].push_back("Sahara Occidentala");
    countries[1].push_back("Sudan");
    countries[1].push_back("Sudanul de Sud");
    countries[1].push_back("Tunisia");
    countries[1].push_back("Africa de Sud");
    countries[1].push_back("Botswana");
    countries[1].push_back("Eswatini");
    countries[1].push_back("Lesotho");
    countries[1].push_back("Namibia");
    countries[1].push_back("Zimbabwe");
    countries[1].push_back("Benin");
    countries[1].push_back("Burkina Faso");
    countries[1].push_back("Capul Verde");
    countries[1].push_back("Cote d Ivoire");
    countries[1].push_back("Gambia");
    countries[1].push_back("Ghana");
    countries[1].push_back("Guineea");
    countries[1].push_back("Guineea-Bissau");
    countries[1].push_back("Liberia");
    countries[1].push_back("Mali");
    countries[1].push_back("Mauritania");
    countries[1].push_back("Niger");
    countries[1].push_back("Senegal");
    countries[1].push_back("Sierra Leone");
    countries[1].push_back("Togo");
    curiosities[1].push_back("Continentul african este cea mai veche zona populata din lume");
    curiosities[1].push_back("Africa este al doilea cel mai populat continent.");
    curiosities[1].push_back("Conectate la internet in Africa sunt mai putine personae decat sunt conectate doar in New York");
    curiosities[1].push_back("Africa are aproximativ 30% din toate resursele minerale ramase pe Pamant");
    curiosities[1].push_back("Lacul Malawi are mai multe specii de pesti decat orice alt sistem de apa dulce de pe Pamant");

    //america de nord
    surface[2] = 247100000;
    population[2] = 579000000;
    countries[2].push_back("Antigua si Barbuda");
    countries[2].push_back("Bahamas");
    countries[2].push_back("Barbados");
    countries[2].push_back("Beliza");
    countries[2].push_back("Canada");
    countries[2].push_back("Costa Rica");
    countries[2].push_back("Cuba");
    countries[2].push_back("Dominica");
    countries[2].push_back("Republica Dominicana");
    countries[2].push_back("El Salvador");
    countries[2].push_back("Grenada");
    countries[2].push_back("Guatemala");
    countries[2].push_back("Haiti");
    countries[2].push_back("Honduras");
    countries[2].push_back("Jamaica");
    countries[2].push_back("Mexic");
    countries[2].push_back("Nicaragua");
    countries[2].push_back("Panama");
    countries[2].push_back("Sfanta Lucia");
    countries[2].push_back("Sfantul Cristofor si Nevis");
    countries[2].push_back("Sfantul Vicentiu si Grenadine");
    countries[2].push_back("Statele Unite ale Americii");
    countries[2].push_back("Trinidad-Tobago");
    countries[2].push_back("Insulele Virgine Britanice");
    curiosities[2].push_back("Zi de zi sunt servite in SUA aproximativ 100 de hectare de pizza");
    curiosities[2].push_back("Daca ai in buzunar 10 dolari si nu ai datorii, esti mai bogat decat 25% dintre americani");
    curiosities[2].push_back("7% dintre americani sustin ca nu fac baie niciodata");
    curiosities[2].push_back("A fi angajat la McDonalds in SUA este ceva normal. Astfel, 1 din 8 americani a fost la un moment dat angajat la MacDonalds");
    curiosities[2].push_back("Americanii cheltuie in fiecare zi 5 centi doar prin tragerea apei la toaleta");

    //america de sud
    surface[3] = 17840000;
    population[3] = 422500000;
    countries[3].push_back("Argentina");
    countries[3].push_back("Bolivia");
    countries[3].push_back("Brazilia");
    countries[3].push_back("Chile");
    countries[3].push_back("Columbia");
    countries[3].push_back("Ecuador");
    countries[3].push_back("Insulele Falkland");
    countries[3].push_back("Guyana Franceza");
    countries[3].push_back("Guyana");
    countries[3].push_back("Paraguay");
    countries[3].push_back("Peru");
    countries[3].push_back("Surinam");
    countries[3].push_back("Uruguay");
    countries[3].push_back("Venezuela");
    curiosities[3].push_back("America de Sud este un continent traversat de ecuator, cu suprafata majoritara in emisfera sudica");
    curiosities[3].push_back("America de Sud este situata intre Oceanul PAcific si Oceanul Atlantic");
    curiosities[3].push_back("Anzii constituie cel mai lung sistem muntos de pe Terra; se desfasoara in vestul Americii de Sud, paralel cu coasta Pacificului, de la tarmul Marii Caraibilor, pana la capul Horn, pe 7600km");
    curiosities[3].push_back("Chimborazo este cel mai inalt munte de pe Terra, masurat de la centrul planetei noastre");
    curiosities[3].push_back("Raul Casiquiare, aflat in sudul Venezuelei, formeaza cea mai importanta difluenta, legand cursurile a doua mari fluvii: Amazon si Orinoco");

    //asia
    surface[4] = 44580000;
    population[4] = 4561000000;
    countries[4].push_back("China");
    countries[4].push_back("Coreea de Nord");
    countries[4].push_back("Coreea de Sud");
    countries[4].push_back("Japonia");
    countries[4].push_back("Kazahstan");
    countries[4].push_back("Kargazstan");
    countries[4].push_back("Tadjikistan");
    countries[4].push_back("Turkmenistan");
    countries[4].push_back("Uzbekistan");
    countries[4].push_back("Azerbaidjan");
    countries[4].push_back("Brunei");
    countries[4].push_back("Cambodgia");
    countries[4].push_back("Filipine");
    countries[4].push_back("Indonezia");
    countries[4].push_back("Laos");
    countries[4].push_back("Malaezia");
    countries[4].push_back("Myanmar");
    countries[4].push_back("Singapore");
    countries[4].push_back("Timorul de Est");
    countries[4].push_back("Thailanda");
    countries[4].push_back("Vietnam");
    countries[4].push_back("Afhanistan");
    countries[4].push_back("Bangladesh");
    countries[4].push_back("Bhutan");
    countries[4].push_back("India");
    countries[4].push_back("Maldive");
    countries[4].push_back("Nepal");
    countries[4].push_back("Pakistan");
    countries[4].push_back("Sri Lanka");
    countries[4].push_back("Arabia Saudita");
    countries[4].push_back("Armenia");
    countries[4].push_back("Azerbaijan");
    countries[4].push_back("Bahrain");
    countries[4].push_back("Cipru");
    countries[4].push_back("Emiratele Arabe Unite");
    countries[4].push_back("Fasia Gaza");
    countries[4].push_back("Georgia");
    countries[4].push_back("Iordania");
    countries[4].push_back("Irak");
    countries[4].push_back("Iran");
    countries[4].push_back("Israel");
    countries[4].push_back("Liban");
    countries[4].push_back("Kuweit");
    countries[4].push_back("Nagorno-Karabakh");
    countries[4].push_back("Oman");
    countries[4].push_back("Peninsula Sinai");
    countries[4].push_back("Palestina");
    countries[4].push_back("Qatar");
    countries[4].push_back("Siria");
    countries[4].push_back("Turcia");
    countries[4].push_back("Yemen");
    curiosities[4].push_back("Este cel mai mare continent de pe planeta");
    curiosities[4].push_back("Asia are cel mai mare numar de miliardari din lume");
    curiosities[4].push_back("Este incredibil de biodiversa");
    curiosities[4].push_back("60% din populatia lumii traieste in Asia");
    curiosities[4].push_back("Insectele sunt consumate ca delicatese in unele tari asiatice");

    //europa
    surface[5] = 4233000;
    population[5] = 748324907;
    countries[5].push_back("Albania");
    countries[5].push_back("Andorra");
    countries[5].push_back("Armenia");
    countries[5].push_back("Austria");
    countries[5].push_back("Azerbaijan");
    countries[5].push_back("Belarus");
    countries[5].push_back("Belgia");
    countries[5].push_back("Bosnia si Hertegovina");
    countries[5].push_back("Bulgaria");
    countries[5].push_back("Cipru");
    countries[5].push_back("Croatia");
    countries[5].push_back("Danemarca");
    countries[5].push_back("Elvetia");
    countries[5].push_back("Estonia");
    countries[5].push_back("Finlanda");
    countries[5].push_back("Franta");
    countries[5].push_back("Georgia");
    countries[5].push_back("Germania");
    countries[5].push_back("Grecia");
    countries[5].push_back("Irlanda");
    countries[5].push_back("Islanda");
    countries[5].push_back("Italia");
    countries[5].push_back("Kazakhstan");
    countries[5].push_back("Letonia");
    countries[5].push_back("Liechtenstein");
    countries[5].push_back("Lituania");
    countries[5].push_back("Luxemburg");
    countries[5].push_back("Macedonia de Nord");
    countries[5].push_back("Malta");
    countries[5].push_back("Monaco");
    countries[5].push_back("Muntenegru");
    countries[5].push_back("Norvegia");
    countries[5].push_back("Polonia");
    countries[5].push_back("Portugalia");
    countries[5].push_back("Regatul Unit");
    countries[5].push_back("Republica Ceha");
    countries[5].push_back("Republica Moldova");
    countries[5].push_back("Romania");
    countries[5].push_back("Rusia");
    countries[5].push_back("San Marino");
    countries[5].push_back("Serbia");
    countries[5].push_back("Slovacia");
    countries[5].push_back("Slovenia");
    countries[5].push_back("Spania");
    countries[5].push_back("Suedia");
    countries[5].push_back("Turcia");
    countries[5].push_back("Tarile de Jos");
    countries[5].push_back("Ucraina");
    countries[5].push_back("Ungaria");
    countries[5].push_back("Vatican");
    curiosities[5].push_back("Istanbul este singurul oras din lume situat pe doua continente, Europa si Asia");
    curiosities[5].push_back("Rusia este cel mai mare stat din Europa, atat ca suprafata, cat si ca populatie");
    curiosities[5].push_back("Europa produce putin peste 18% din cantitatea de petrol la nivel mondial");
    curiosities[5].push_back("In Europa se afla cea mai mica tara din lume. Vaticanul are o suprafata de numai 0,44km patrati");
    curiosities[5].push_back("Cel mai vizitat obiectiv turistic din europa este ...Disneyland Paris");

    //australia
    surface[6] = 7692000;
    population[6] = 25690000;
    curiosities[6].push_back("Australia gazduieste cel mai multe camile din lume");
    curiosities[6].push_back("Australia a fost unul dintre membrii fondatori ai Organizatiei Natiunilor Unite");
    curiosities[6].push_back("Melbourne are cea mai mare populatie de greci din lume, cu exceptia Atenei");
    curiosities[6].push_back("In anul 1880 Melbourne a fost cel mai bogat oras din lume");
    curiosities[6].push_back("Cea mai veche fosila din lume care are aproximativ 3,4 miliarde de ani a fost gasita in Australia");
}

void displayCountries(int ind) {
    for(auto i : countries[ind]) cout << i << "\n";
}

void displayMap() {
    cout << "           . _..::__:  ,- -._                 ,     _,.__             " << endl;
    cout << "   _.___ _ _<_>`!(._`.`-.    /         _._     `_ ,_/      -._.---.-.__" << endl;
    cout << ">.{         `-==, ,._\\{  \\  / {)      / _  >_,-  `                _" << endl;
    cout << "  \\_.:--.       `._ )`^-.          , [_/(                       __,/-  " << endl;
    cout << "         \\              _L        oD_,--                 )     /. (|   " << endl;
    cout << "          |           ,           _)_.\\\\._<>                _,  /      " << endl;
    cout << "          `.         /           [_/_ ` ` (                < }  )      " << endl;
    cout << "           \\\\    .-. )           /   `-  ..  `:._          _)          " << endl;
    cout << "    `        \\  (  `(           /         `:\\  > \\  ,-^.  /            " << endl;
    cout << "              `._,   ""          |           \\`    \\|   ?_)  {\\         " << endl;
    cout << "                 `=.---.        `._._       ,       `  |  ,-  .        " << endl;
    cout << "                   |    `-._         |     /          `:`<_|h--._      " << endl;
    cout << "                   (        >        .     | ,          `=.__.`- \\     " << endl;
    cout << "                    `.     /         |     |{|              ,-.,\\     ." << endl;
    cout << "                     |   ,            \\   / `             ,      \\     " << endl;
    cout << "                     |  /              |_                 |  __  /     " << endl;
    cout << "                     | |                                   -   `-    \\." << endl;
    cout << "                     |/                                              / " << endl;
    cout << "                     \\.                                                " << endl;
}

void displayAfrica() {
    cout << "           ___________" << endl;
    cout << "           / |       | |" << endl;
    cout << "        ,  ,          \\/ ,_    __" << endl;
    cout << "     , __/             |     ,|    -,,,,,,," << endl;
    cout << "   ,/  _| ,            |                |   \\" << endl;
    cout << "   |  |   | ,           \\               |    \\" << endl;
    cout << "   |__|   |   ,           ,             |     \\" << endl;
    cout << "  /       |      ,        ,_     --- -_, ______\\" << endl;
    cout << " /        |         ,,_-      |        |         ," << endl;
    cout << "|_________|         |         /        |        /  ,,-----|" << endl;
    cout << "|__  |        ,____/         |        _|       /    |___  /" << endl;
    cout << " \\___|      , _, |_,-,_______|         |       /      ,  /" << endl;
    cout << "  \\,  _ , _/  ,, , ,|        |          \\       |      , " << endl;
    cout << "   \\ / |_ ,  |  \\||||       ,  |      , |    _      |, " << endl;
    cout << "      ,    , |  ||||| __ ,    _|_ ,     |    |  ---/" << endl;
    cout << "         ,____,______ |     /           \\   |    /" << endl;
    cout << "                      |_____|_      __       \\   |" << endl;
    cout << "                     |  |  /           |      \\ /" << endl;
    cout << "                      \\ / |            |       /" << endl;
    cout << "                       \\--             |      /" << endl;
    cout << "                       |   \\__        _|__    |" << endl;
    cout << "                       |      |__     |    ,,,|" << endl;
    cout << "                       |         |____|   /   |" << endl;
    cout << "                       /         _|    ,, _   |         /\\" << endl;
    cout << "                      |__________|___,   ,,  /       __/ |" << endl;
    cout << "                       \\      ---     \\,/  ,        /   /" << endl;
    cout << "                        \\     |    ,,,  \\_/        /   /" << endl;
    cout << "                         |    |_,        |/        |  |" << endl;
    cout << "                         |    |       []_|         | /" << endl;
    cout << "                          \\___         /" << endl;
    cout << "                           \\       __, " << endl;
    cout << "                            \\_____/" << endl;
}

void displayAmericaN() {
    cout << "________               /                                         \\" << endl;
    cout << "        \\                                                         \\" << endl;
    cout << "         \\            \\                          /~~~~~~~~~~~~\\    \\ " << endl;
    cout << "____      ~~~~~\\      /                         /              \\   /" << endl;
    cout << "    \\           ~~~~~~                      /~~~                \\_/" << endl;
    cout << "     |                                     /             /~~\\    _" << endl;
    cout << "     |                                     \\            |    \\  / \\" << endl;
    cout << "     |                                      |       ___/      \\/   \\_" << endl;
    cout << "     |                                      \\______/                 \\" << endl;
    cout << "     \\   ,__                                                  _ _____|" << endl;
    cout << "      \\~\\|  ~~---___              ,                          | \\    " << endl;
    cout << "       |      / |   ~~~~~~~|~~~~~| ~~---,                  _/,  >" << endl;
    cout << "      /~-_--__| |          |     \\     / ~\\~~/          /~| ||, " << endl;
    cout << "      |       /  \\         |------|   {    / /~)     __-   ,|_\\," << endl;
    cout << "     /       |    |~~~~~~~~|      \\    \\   | |  ~\\  |_____,|~,- " << endl;
    cout << "     |~~--__ |    |        |____  |~~~~~|--| |__ /_-      {,~" << endl;
    cout << "     |   |  ~~~|~~|        |    ~~\\     /  `-  |`~ |~_____{/" << endl;
    cout << "     |   |     |   ---------,      \\----|   |  |  ,  ~/~\\,|`" << endl;
    cout << "      ,  \\     |    |       |~~~~~~~|    \\  | , ~~\\  /    |" << endl;
    cout << "      |   \\    |    |       |       |     \\_-~    /`~___--\\" << endl;
    cout << "       ,   \\  ,-----|-------+------- _____/__----~~/      /" << endl;
    cout << "        _    \\|     |      |~~~|     |    |      _/-,~~-,/" << endl;
    cout << "         \\    |     |      |   |_    |    /~~|~~\\    \\,/" << endl;
    cout << "          ~~~-      |      |     `~~~\\___|   |   |    /" << endl;
    cout << "          \\ ~~~-,-,_  | _____|          |  /   | ,- -~\\" << endl;
    cout << "           \\     -`~ ~  \\             |  `--,~~~~-~~,  \\" << endl;
    cout << "            \\ /\\    `~ ~  \\~\\      /~~~`---`         |  \\" << endl;
    cout << "            _\\ \\\\          \\/~\\  /                   \\  |" << endl;
    cout << "              \\__ \\\\             \\ |                      \\ " << endl;
    cout << " 	         \\ \\\\.             \\" << endl;
    cout << "                  \\ \\ \\             `~~" << endl;
    cout << "	           \\\\ \\.             /" << endl;
    cout << "        	    L  \\  \\            |" << endl;
    cout << "	             \\_\\  \\           |             _.----," << endl;
    cout << "        	          |           \\           !     /" << endl;
    cout << "              	         ._           \\_      __/    _/" << endl;
    cout << "                          \\_             --      __/" << endl;
    cout << "                            \\.__                |" << endl;
    cout << "                                  .__  __.._   __\\" << endl;
    cout << "                                              ./  `" << endl;
}

void displayAmericaS() {
    cout << "       ~~~~________" << endl;
    cout << "      /            \\____" << endl;
    cout << "     /                   \\" << endl;
    cout << "   _|                     \\" << endl;
    cout << "  /                        ~__" << endl;
    cout << " /                            ~~__ " << endl;
    cout << "|                                 ~~___" << endl;
    cout << "|                                      \\  " << endl;
    cout << " \\                                     |" << endl;
    cout << "  \\                                   /" << endl;
    cout << "   \\                                 /" << endl;
    cout << "    \\_                              /" << endl;
    cout << "      \\                             |" << endl;
    cout << "       \\                            |" << endl;
    cout << "        |                          /" << endl;
    cout << "        |                       __/" << endl;
    cout << "        |                     /" << endl;
    cout << "        |                    |" << endl;
    cout << "        |                   / " << endl;
    cout << "        |                  /   " << endl;
    cout << "        |                _/" << endl;
    cout << "        |               /" << endl;
    cout << "        |            __/" << endl;
    cout << "        |           /" << endl;
    cout << "        |          /" << endl;
    cout << "        |         /" << endl;
    cout << "        |        /" << endl;
    cout << "        \\       /" << endl;
    cout << "         \\     |" << endl;
    cout << "          \\_____\\" << endl;
}

void displayAsia() {
    cout << "                                                                    +---+" << endl;
    cout << "                                                                   /    |" << endl;
    cout << "                                                                   \\    +       " << endl;
    cout << "                   +---+                                           /     \\      " << endl;
    cout << "                  /     \\                             +-----------+       +     " << endl;
    cout << "                 /  +-+ /                 -+         /             \\      |     " << endl;
    cout << "                +   | |/                 / +--------+              |      |     " << endl;
    cout << "               / \\   \\                  /           |              \\      +     " << endl;
    cout << "              /   +   +-----+    /|  --+            +       +-------+    /      " << endl;
    cout << "       +-+---+    |          \\  / | /  |             \\     /|        \\_ |       " << endl;
    cout << "      /   \\       +           \\/  +-   |              \\   / |        / ||       " << endl;
    cout << "     /     \\     / \\             /     |               +-+  +--+    |  | \\      " << endl;
    cout << "    /       +---+   |           /      |              /         \\  ++  |  |     " << endl;
    cout << "   +        |       +-+      +-+       +         +---+           + |    \\ |     " << endl;
    cout << "   |        +--+       \\    /         /         /    +           | |     \\|     " << endl;
    cout << "   +       /    \\       +--+         /      +--+      \\       +--+-+-+          " << endl;
    cout << "  +-------+      \\      |           /\\     /           +-+   / \\      \\         " << endl;
    cout << " /         \\     |      |       +--+  +   /               \\ /   \\      \\        " << endl;
    cout << "+          |     |      |      /      |  |                 +     +--+  / +----+ " << endl;
    cout << "           +-+   |      \\     /       +  |                /         |  \\ |    | " << endl;
    cout << "   +--+--+/   \\  |       +---+         \\/              +--+         |  / |    | " << endl;
    cout << "  /  /     \\   +-+      /     \\        /              /   |      +--+-+  +----+ " << endl;
    cout << "-+  +       \\     \\    +       \\      /              /    |     /     |         " << endl;
    cout << "             +     +   |        +----+       +------+     |     \\     |   +---+ " << endl;
    cout << " |  +---+    |     |   |              \\-----/             +-+    +--+ |  +    | " << endl;
    cout << " |       \\   +--+  +-+-+--+                /             /   \\   |  | |  |    | " << endl;
    cout << " +        \\     \\-  /    /             +--+             |     \\  ++ +-+  +  +-+ " << endl;
    cout << "  \\        +-+           \\  +--------+-+   \\--+       +-+      +-/       |  |   " << endl;
    cout << "   +--+      |     |     / /         |        /\\     /\\          \\       |  |   " << endl;
    cout << "       \\     ++    +    /-+          |       +  +---+  \\          \\      +--+   " << endl;
    cout << "       /+---/  \\    \\  /             +       |  |       \\          \\            " << endl;
    cout << "      /     \\   +----++--+          /    +---+  +        \\          \\           " << endl;
    cout << "----- \\     |    |        \\        +    /      /          \\          \\          " << endl;
    cout << "       /    +    +         +-------+   /      /            +----------+         " << endl;
    cout << "       -----+     \\       /        |  +      +             |          |      " << endl;
    cout << "    / |      \\     +     +      +--+  |      |             /          |         " << endl;
    cout << "    \\ +       \\    |     |     /   |  |      |     +------+           |         " << endl;
    cout << "    |  \\       \\   |     |    /  +-+--       |    /        \\          +         " << endl;
    cout << "    +   \\       +--+     |---+  /                   +       +--+     /          " << endl;
    cout << "    |    +      |   \\    +     /                     \\     /    \\   /           " << endl;
    cout << "    |    |      |    \\   |     \\       /  |     |     \\   /      +-+            " << endl;
    cout << "----+    |      +     \\  |      +-+---+   |     |     |\\ /      /        +---+  " << endl;
    cout << "    |    |       \\     +-+-+   /  |      /      |     | +--+---+        /    |  " << endl;
    cout << "    |    +-----+--+--+      \\ /   \\     +-------+     +    |    \\      +     |  " << endl;
    cout << "    |    |     |     |       +     + +--+       |    /     |     +     |     +  " << endl;
    cout << "    |    |     |     |       |     |/           +   /\\     |     |     +    /   " << endl;
    cout << "    |    +-----+-----+       +     +             \\ +  \\     \\    |      \\  +-+  " << endl;
    cout << "    +                         \\    |              \\|   +-+---++  +       +-+ |  " << endl;
    cout << "     \\                         \\   |               +     |     \\/          / /  " << endl;
    cout << "      +-----+                   \\  +               |     |     /          +-+   " << endl;
    cout << "           /                     \\/  ++            + +---+    /                 " << endl;
    cout << "          /                         /  \\            \\ \\  +---+                  " << endl;
    cout << "         /                              +            + +                        " << endl;
    cout << "        /                         |     |            + |          +--+          " << endl;
    cout << "-------+                           \\   /            + \\|         /   |          " << endl;
    cout << "                                    +-+             |\\          /    |          " << endl;
    cout << "                                                    | \\        /     |          " << endl;
    cout << "                                                    +  +--+   +      |  /\\  +---" << endl;
    cout << "                                                    \\     \\   \\     |  | +-+" << endl;
    cout << "                                                      \\     \\   +----+  \\-      " << endl;
    cout << "                                                       +-----+            \\" << endl;
    cout << "                                                               +-----+     +--+" << endl;
    cout << "                                                              /       \\       +-" << endl;
    cout << "                                                              \\        |        " << endl;
    cout << "                                                               +-------+        " << endl;
}

void displayEurope() {
    cout << "                -.            .      .-. " << endl;
    cout << "                             /      / ./ " << endl;
    cout << "              _  __,     .--       / < " << endl;
    cout << "             ~_-~ /     <         <   \\_ .-~7 " << endl;
    cout << "           _. \\   >      \\.- \\     >`   ~ .-~ " << endl;
    cout << "          <  ><  /         ,  7   <      ~7 " << endl;
    cout << "          /_/  ! \\       .-L  \\  _//   < ~ " << endl;
    cout << "          ~  .-~  !      ! /o& `  .     7 " << endl;
    cout << "             _>_._ >  _.-   -._.-._.--./ " << endl;
    cout << "             -~   ~._/                                                .  " << endl;
    cout << "              ,-.-                                                 .-~< " << endl;
    cout << "             <                                                  __/    > -  " << endl;
    cout << "              \\                                               -~ ___--/ " << endl;
    cout << "               7                                ..   .       /_//     \\__ " << endl;
    cout << "               !       _.-.     ..             <  ~v~                    \\ " << endl;
    cout << "        .-~---    .-.-~    ~\\  <  \\            /            |          __/ " << endl;
    cout << "        )         >      o  <   >  \\           \\_.--._      |O        |    .__,--_ " << endl;
    cout << "       /       .-       <>   \\  \\   7       .               )        / d  . _>   /. " << endl;
    cout << "       7       > . -          > _\\  !   _,-  `.             \\       /.._  .)    < " << endl;
    cout << "       ~--,.--            ._ /.- ~` <   \\ .   \\              `     |<   \\  `-.__/ " << endl;
    cout << "                           7/ ~       \\.,< .  ` `-~-.-~       |    /  \\__//.--...<| " << endl;
    cout << "                                        __  . `               -.__\\\\  -    --~|/ " << endl;
}

void displayAustralia() {
    cout << "                    _,__        .: " << endl;
    cout << "                   <*  /        | \\ " << endl;
    cout << "               .-./     |.     :  :, " << endl;
    cout << "              /            -._/     \\_ " << endl;
    cout << "             /                        \\ " << endl;
    cout << "           .                          *:  " << endl;
    cout << "        .-                              ; " << endl;
    cout << "        |                               | " << endl;
    cout << "        \\                              / " << endl;
    cout << "         |                            / " << endl;
    cout << "          \\*        __.--._          / " << endl;
    cout << "           \\     _.        \\:.       | " << endl;
    cout << "           >__,-              \\_/*_.-  " << endl;
    cout << "                                  " << endl;
    cout << "                                :--, " << endl;
    cout << "                                  / " << endl;
}

void africa() {
    system("cls");
    displayAfrica(); cout << endl;
    cout << "1 -> lista tari" << endl;
    cout << "2 -> suprafata" << endl;
    cout << "3 -> populatie" << endl;
    cout << "4 -> curiozitati" << endl;
    cout << "5 -> exit" << endl;
    int opt; cout << "optiune -> "; cin >> opt;
    string var[] = {"", "lista tari", "suprafata", "populatie", "curiozitati", "exit"};
    cout << "ati ales optiunea " << var[opt] << endl;
    if(opt==5) return ;
    if(opt==1) {
        system("cls"); displayAfrica(); cout << endl;
        displayCountries(1);
    }
    else if(opt==2) {
        system("cls"); displayAfrica(); cout << endl;
        cout << "suprafata africii este de " << surface[1] << " km^2" << endl;
    }
    else if(opt==3) {
        system("cls"); displayAfrica(); cout << endl;
        cout << "populatia africii este de " << population[1] << endl;
    }
    else if(opt==4) {
        system("cls"); displayAfrica(); cout << endl;
        if(afisate==5)
            cout << "ai epuizat curiozitatile, curiosule" << endl;
        else {
            int pos = rand() % 5;
            while(shown[pos]) pos = rand() % 5;
            shown[pos] = true; afisate++;
            cout << curiosities[1][pos] << endl;
        }
    }
    system("pause");
    africa();
}

void americaN() {
    system("cls");
    displayAmericaN(); cout << endl;
    cout << "1 -> lista tari" << endl;
    cout << "2 -> suprafata" << endl;
    cout << "3 -> populatie" << endl;
    cout << "4 -> curiozitati" << endl;
    cout << "5 -> exit" << endl;
    int opt; cout << "optiune -> "; cin >> opt;
    string var[] = {"", "lista tari", "suprafata", "populatie", "curiozitati", "exit"};
    cout << "ati ales optiunea " << var[opt] << endl;
    if(opt==5) return ;
    if(opt==1) {
        system("cls"); displayAmericaN(); cout << endl;
        displayCountries(2);
    }
    else if(opt==2) {
        system("cls"); displayAmericaN(); cout << endl;
        cout << "suprafata africii este de " << surface[2] << " km^2" << endl;
    }
    else if(opt==3) {
        system("cls"); displayAmericaN(); cout << endl;
        cout << "populatia africii este de " << population[2] << endl;
    }
    else if(opt==4) {
        system("cls"); displayAmericaN(); cout << endl;
        if(afisate==5)
            cout << "ai epuizat curiozitatile, curiosule" << endl;
        else {
            int pos = rand() % 5;
            while(shown[pos]) pos = rand() % 5;
            shown[pos] = true; afisate++;
            cout << curiosities[2][pos] << endl;
        }
    }
    system("pause");
    americaN();
}

void americaS() {
    system("cls");
    displayAmericaS(); cout << endl;
    cout << "1 -> lista tari" << endl;
    cout << "2 -> suprafata" << endl;
    cout << "3 -> populatie" << endl;
    cout << "4 -> curiozitati" << endl;
    cout << "5 -> exit" << endl;
    int opt; cout << "optiune -> "; cin >> opt;
    string var[] = {"", "lista tari", "suprafata", "populatie", "curiozitati", "exit"};
    cout << "ati ales optiunea " << var[opt] << endl;
    if(opt==5) return ;
    if(opt==1) {
        system("cls"); displayAmericaS(); cout << endl;
        displayCountries(3);
    }
    else if(opt==2) {
        system("cls"); displayAmericaS(); cout << endl;
        cout << "suprafata africii este de " << surface[3] << " km^2" << endl;
    }
    else if(opt==3) {
        system("cls"); displayAmericaS(); cout << endl;
        cout << "populatia africii este de " << population[3] << endl;
    }
    else if(opt==4) {
        system("cls"); displayAmericaS(); cout << endl;
        if(afisate==5)
            cout << "ai epuizat curiozitatile, curiosule" << endl;
        else {
            int pos = rand() % 5;
            while(shown[pos]) pos = rand() % 5;
            shown[pos] = true; afisate++;
            cout << curiosities[3][pos] << endl;
        }
    }
    system("pause");
    americaS();
}

void asia() {
    system("cls");
    displayAsia(); cout << endl;
    cout << "1 -> lista tari" << endl;
    cout << "2 -> suprafata" << endl;
    cout << "3 -> populatie" << endl;
    cout << "4 -> curiozitati" << endl;
    cout << "5 -> exit" << endl;
    int opt; cout << "optiune -> "; cin >> opt;
    string var[] = {"", "lista tari", "suprafata", "populatie", "curiozitati", "exit"};
    cout << "ati ales optiunea " << var[opt] << endl;
    if(opt==5) return ;
    if(opt==1) {
        system("cls"); displayAsia(); cout << endl;
        displayCountries(4);
    }
    else if(opt==2) {
        system("cls"); displayAsia(); cout << endl;
        cout << "suprafata africii este de " << surface[4] << " km^2" << endl;
    }
    else if(opt==3) {
        system("cls"); displayAsia(); cout << endl;
        cout << "populatia africii este de " << population[4] << endl;
    }
    else if(opt==4) {
        system("cls"); displayAsia(); cout << endl;
        if(afisate==5)
            cout << "ai epuizat curiozitatile, curiosule" << endl;
        else {
            int pos = rand() % 5;
            while(shown[pos]) pos = rand() % 5;
            shown[pos] = true; afisate++;
            cout << curiosities[4][pos] << endl;
        }
    }
    system("pause");
    asia();
}

void europe() {
    system("cls");
    displayEurope(); cout << endl;
    cout << "1 -> lista tari" << endl;
    cout << "2 -> suprafata" << endl;
    cout << "3 -> populatie" << endl;
    cout << "4 -> curiozitati" << endl;
    cout << "5 -> exit" << endl;
    int opt; cout << "optiune -> "; cin >> opt;
    string var[] = {"", "lista tari", "suprafata", "populatie", "curiozitati", "exit"};
    cout << "ati ales optiunea " << var[opt] << endl;
    if(opt==5) return ;
    if(opt==1) {
        system("cls"); displayEurope(); cout << endl;
        displayCountries(5);
    }
    else if(opt==2) {
        system("cls"); displayEurope(); cout << endl;
        cout << "suprafata africii este de " << surface[5] << " km^2" << endl;
    }
    else if(opt==3) {
        system("cls"); displayEurope(); cout << endl;
        cout << "populatia africii este de " << population[5] << endl;
    }
    else if(opt==4) {
        system("cls"); displayEurope(); cout << endl;
        if(afisate==5)
            cout << "ai epuizat curiozitatile, curiosule" << endl;
        else {
            int pos = rand() % 5;
            while(shown[pos]) pos = rand() % 5;
            shown[pos] = true; afisate++;
            cout << curiosities[5][pos] << endl;
        }
    }
    system("pause");
    europe();
}

void australia() {
    system("cls");
    displayAustralia(); cout << endl;
    cout << "1 -> lista tari" << endl;
    cout << "2 -> suprafata" << endl;
    cout << "3 -> populatie" << endl;
    cout << "4 -> curiozitati" << endl;
    cout << "5 -> exit" << endl;
    int opt; cout << "optiune -> "; cin >> opt;
    string var[] = {"", "lista tari", "suprafata", "populatie", "curiozitati", "exit"};
    cout << "ati ales optiunea " << var[opt] << endl;
    if(opt==5) return ;
    if(opt==1) {
        system("cls"); displayAustralia(); cout << endl;
        cout << "Australia este o tara ce ocupa in intregime continentul cu acelasi nume" << endl;
    }
    else if(opt==2) {
        system("cls"); displayAustralia(); cout << endl;
        cout << "suprafata africii este de " << surface[6] << " km^2" << endl;
    }
    else if(opt==3) {
        system("cls"); displayAustralia(); cout << endl;
        cout << "populatia africii este de " << population[6] << endl;
    }
    else if(opt==4) {
        system("cls"); displayAustralia(); cout << endl;
        if(afisate==5)
            cout << "ai epuizat curiozitatile, curiosule" << endl;
        else {
            int pos = rand() % 5;
            while(shown[pos]) pos = rand() % 5;
            shown[pos] = true; afisate++;
            cout << curiosities[6][pos] << endl;
        }
    }
    system("pause");
    australia();
}
