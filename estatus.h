void status(string clases){
    pesonagem p;
    cout << "digite o nome do seu personagem: ";
    cin >> p.nome;
    if (clases == "Mago"){
        p.vida = 60;
        p.mana = 150;
        p.ata = 30;
        p.def = 20;
        p.vel = 35;
    }
    if (clases == "Guerreiro"){
        p.vida = 150;
        p.mana = 40;
        p.ata = 120;
        p.def = 50;
        p.vel = 20;
    }
    if (clases == "ladino"){
        p.vida = 100;
        p.mana = 80;
        p.ata = 80;
        p.def = 30;
        p.vel = 60;
    }
} 