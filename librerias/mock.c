#include "mock.h"

const char directores[][DIM_DIRECTOR] = {
    "Steven Spielberg",
    "Martin Scorsese",
    "Quentin Tarantino",
    "Christopher Nolan",
    "Alfred Hitchcock",
    "Stanley Kubrick",
    "Francis Ford Coppola",
    "Ridley Scott",
    "James Cameron",
    "Peter Jackson",
    "Tim Burton",
    "David Fincher",
    "Coen Brothers",
    "Clint Eastwood",
    "Guillermo del Toro",
    "Alejandro G. Inarritu",
    "Wes Anderson",
    "Sofia Coppola",
    "Paul Thomas Anderson",
    "Denis Villeneuve",
    "Spike Lee",
    "Darren Aronofsky",
    "Woody Allen",
    "George Lucas",
    "Robert Zemeckis",
    "Ron Howard",
    "John Carpenter",
    "Roman Polanski",
    "Baz Luhrmann",
    "Sam Mendes",
    "Michael Bay",
    "Richard Linklater",
    "Lars von Trier",
    "M. Night Shyamalan",
    "David Lynch",
    "J.J. Abrams",
    "Greta Gerwig",
    "Taika Waititi",
    "Jordan Peele",
    "Patty Jenkins",
};

const char titulosPeliculas[][DIM_TITULO_PELICULA] = {
    "The Godfather",
    "The Dark Knight",
    "Pulp Fiction",
    "The Lord of the Rings: The Return of the King",
    "Forrest Gump",
    "Star Wars: The Empire Strikes Back",
    "Inception",
    "Fight Club",
    "The Lord of the Rings: The Fellowship of the Ring",
    "The Matrix",
    "The Lord of the Rings: The Two Towers",
    "The Silence of the Lambs",
    "Seven Samurai",
    "Se7en",
    "Schindler's List",
    "Interstellar",
    "The Good, the Bad and the Ugly",
    "The Pianist",
    "Life is Beautiful",
    "The Departed",
    "Gladiator",
    "Saving Private Ryan",
    "Intouchables",
    "The Prestige",
    "City of God",
    "The Lion King",
    "Memento",
    "Parasite",
    "La La Land",
    "Avengers: Endgame",
    "Coco",
    "Django Unchained",
    "Titanic",
    "Pan's Labyrinth",
    "The Shining",
    "Whiplash",
    "The Grand Budapest Hotel",
    "Die Hard",
    "Star Wars: A New Hope",
    "Amelie",
    "Princess Mononoke",
    "Requiem for a Dream",
    "Blade Runner",
    "Toy Story",
    "Spirited Away",
    "The Untouchables",
    "Oldboy",
    "Jurassic Park",
    "American Beauty",
    "Alien",
    "The Shawshank Redemption",
    "Back to the Future",
    "The Social Network",
    "The Green Mile",
    "Braveheart",
    "Goodfellas",
    "The Usual Suspects",
    "L.A. Confidential",
    "Batman Begins",
    "Casino Royale",
    "Reservoir Dogs",
    "Finding Nemo",
    "The Incredibles",
    "Monsters, Inc.",
    "WALL-E",
    "Up",
    "Inside Out",
    "Ratatouille",
    "Cars",
    "Toy Story 2",
    "Toy Story 3",
    "Shrek",
    "Shrek 2",
    "The Iron Giant",
    "How to Train Your Dragon",
    "Kung Fu Panda",
    "Madagascar",
    "Megamind",
    "Puss in Boots",
    "The Prince of Egypt",
    "The Road to El Dorado",
    "Sinbad: Legend of the Seven Seas",
    "Antz",
    "Chicken Run",
    "Wallace & Gromit: The Curse of the Were-Rabbit",
    "Coraline",
    "Fantastic Mr. Fox",
    "The Nightmare Before Christmas",
    "James and the Giant Peach",
    "Corpse Bride",
    "Frankenweenie",
    "ParaNorman",
    "Kubo and the Two Strings",
    "Missing Link",
    "The Secret Life of Pets",
    "Despicable Me",
    "Minions",
    "Sing",
    "The Lorax",
    "Dr. Seuss' Horton Hears a Who!",
    "The Peanuts Movie",
    "A Beautiful Mind",
    "Catch Me If You Can",
    "The Truman Show",
    "Eternal Sunshine of the Spotless Mind",
    "The Pursuit of Happyness",
    "Gladiator",
    "The Revenant",
    "Mad Max: Fury Road",
    "The Dark Knight Rises",
    "The Wolf of Wall Street",
    "The Martian",
    "Guardians of the Galaxy",
    "Doctor Strange",
    "Black Panther",
    "Iron Man",
    "Thor: Ragnarok",
    "Captain America: The Winter Soldier",
    "The Avengers",
    "Avengers: Infinity War",
    "Spider-Man: Homecoming",
    "Wonder Woman",
    "Justice League",
    "Man of Steel",
    "Aquaman",
    "Joker",
    "Logan",
    "Deadpool",
    "Deadpool 2",
    "X-Men: Days of Future Past",
    "The Hobbit: An Unexpected Journey",
    "The Hobbit: The Desolation of Smaug",
    "The Hobbit: The Battle of the Five Armies",
    "Harry Potter and the Sorcerer's Stone",
    "Harry Potter and the Chamber of Secrets",
    "Harry Potter and the Prisoner of Azkaban",
    "Harry Potter and the Goblet of Fire",
    "Harry Potter and the Order of the Phoenix",
    "Harry Potter and the Half-Blood Prince",
    "Harry Potter and the Deathly Hallows: Part 1",
    "Harry Potter and the Deathly Hallows: Part 2",
    "Fantastic Beasts and Where to Find Them",
    "Fantastic Beasts: The Crimes of Grindelwald",
    "The Hunger Games",
    "The Hunger Games: Catching Fire",
    "The Hunger Games: Mockingjay - Part 1",
    "The Hunger Games: Mockingjay - Part 2",
    "Divergent",
    "Insurgent",
    "Allegiant",
};

const char estudios[][DIM_ESTUDIO] = {
    "Warner Bros",
    "Paramount Pictures",
    "Universal Pictures",
    "20th Century Fox",
    "Columbia Pictures",
    "Walt Disney Pictures",
    "MGM",
    "Lionsgate",
    "Sony Pictures",
    "DreamWorks"
};

const char categorias [][DIM_CATEGORIA] = {
    "Accion",
    "Comedia",
    "Drama",
    "Ciencia ficcion",
    "Terror"
};

const char titulosComentarios[][DIM_TITULO_COMENTARIO] = {
    "Gran pelicula",
    "Una obra maestra",
    "Muy entretenida",
    "Mejor de lo esperado",
    "Un clasico",
    "Emotiva y poderosa",
    "Excelentes actuaciones",
    "Visualmente impresionante",
    "Historia cautivadora",
    "No me gusto",
    "Demasiado lenta",
    "Un final sorprendente",
    "Llena de accion",
    "Buena banda sonora",
    "Inolvidable",
    "Recomendada",
    "Aburrida",
    "Un desperdicio de tiempo",
    "Una joya oculta",
    "Sencillamente perfecta",
    "Sobresaliente",
    "Demasiado predecible",
    "Un viaje emocional",
    "Gran direccion",
    "Un guion solido",
    "Actuaciones destacadas",
    "Visuales asombrosos",
    "Falto algo",
    "Una gran sorpresa",
    "No cumplio las expectativas",
    "Un clasico moderno",
    "Fascinante",
    "Demasiado larga",
    "Divertida y ligera",
    "Un poco confusa",
    "Increible desarrollo",
    "Nada especial",
    "Un final perfecto",
    "Simplemente aburrida",
    "Buena pero no genial",
    "Un desastre",
    "Bien hecha",
    "Cautivadora",
    "Para toda la familia",
    "Una pelicula unica",
    "Demasiado dramatica",
    "Bien actuada",
    "Un placer verla",
    "Una experiencia visual",
    "Una perdida de tiempo",
    "Una historia bien contada",
    "Nada memorable",
    "Sorprendentemente buena",
    "No vale la pena",
    "Podria haber sido mejor",
    "Un clasico instantaneo",
    "Demasiado exagerada",
    "Llena de emociones",
    "Un viaje fantastico",
    "Un guion brillante",
    "Demasiado cliche",
    "No me atrapo",
    "Un poco aburrida",
    "Una buena adaptacion",
    "Entretenida pero olvidable",
    "Increiblemente inspiradora",
    "Previsible",
    "Una maravilla visual",
    "Me hizo llorar",
    "Demasiado simple",
    "Una obra de arte",
    "Actuaciones mediocres",
    "Visualmente hermosa",
    "Una historia conmovedora",
    "Un espectaculo visual",
    "No recomendada",
    "Una trama compleja",
    "Una joya cinematografica",
    "Una pelicula divertida",
    "Demasiado intensa",
    "Una pelicula poderosa",
    "Me aburrio",
    "Una pelicula emocionante",
    "No es para todos",
    "Una experiencia unica",
    "Demasiado rebuscada",
    "Un clasico imperdible",
    "Un desarrollo brillante",
    "Llena de sorpresas",
    "Visualmente creativa",
    "Falto desarrollo",
    "Muy impactante",
    "Una comedia divertida",
    "Un drama poderoso",
    "Llena de vida",
    "Una pelicula profunda",
    "Una gran aventura",
    "Un poco lenta",
    "Un deleite visual",
    "Una historia inspiradora",
    "Llena de humor",
    "Una trama solida",
};

const char descripcionComentarios[][DIM_DESCRIPCION_COMENTARIO] = {
    "Esta pelicula es simplemente maravillosa. Me mantuvo entretenido de principio a fin con su historia y personajes.",
    "Una obra maestra del cine moderno. La direccion, el guion y las actuaciones son de primer nivel.",
    "Muy entretenida. Tiene un buen ritmo y mantiene al espectador enganchado durante toda la pelicula.",
    "No esperaba mucho, pero esta pelicula supero todas mis expectativas. Realmente vale la pena verla.",
    "Un clasico que no pasa de moda. Cada vez que la veo, encuentro algo nuevo que disfrutar.",
    "Emotiva y poderosa. Una historia que toca el corazon y deja una impresion duradera.",
    "Las actuaciones son sobresalientes, cada actor entrega una performance memorable.",
    "Visualmente impresionante. Los efectos especiales y la cinematografia son de lo mejor que he visto.",
    "La historia es cautivadora y te mantiene pegado a la pantalla desde el principio hasta el final.",
    "No me gusto. Senti que la trama era floja y los personajes no eran interesantes.",
    "Demasiado lenta para mi gusto. Hubo momentos en los que casi me quedo dormido.",
    "Un final sorprendente que no esperaba para nada. Muy bien logrado.",
    "Llena de accion y emocion. Perfecta para los amantes de las peliculas de accion.",
    "La banda sonora es increible y complementa perfectamente las escenas de la pelicula.",
    "Una pelicula inolvidable que se quedara conmigo por mucho tiempo.",
    "Recomendada para todos. Es una pelicula que no se pueden perder.",
    "Me parecio aburrida y sin gracia. No logro captar mi atencion.",
    "Un desperdicio de tiempo. No la volveria a ver.",
    "Una joya oculta del cine. Merece ser mas conocida.",
    "Sencillamente perfecta. No cambiaria nada de esta pelicula.",
    "Sobresaliente en todos los aspectos. Una pelicula redonda.",
    "Demasiado predecible. Ya sabia lo que iba a pasar desde el principio.",
    "Un viaje emocional que te hace reir y llorar. Totalmente recomendada.",
    "La direccion es excelente. Se nota la mano de un gran director detras de esta pelicula.",
    "Un guion solido y bien estructurado que mantiene el interes del espectador.",
    "Las actuaciones destacadas hacen que la pelicula sea aun mejor.",
    "Visuales asombrosos. Cada escena es un deleite para los ojos.",
    "Falto algo para que fuera perfecta. Aun asi, es una buena pelicula.",
    "Una gran sorpresa. No esperaba que fuera tan buena.",
    "No cumplio las expectativas que tenia. Me decepciono un poco.",
    "Un clasico moderno que se ganara un lugar en la historia del cine.",
    "Fascinante de principio a fin. No pude despegar los ojos de la pantalla.",
    "Demasiado larga. Podrian haberla acortado un poco.",
    "Divertida y ligera. Perfecta para pasar un buen rato sin complicaciones.",
    "Un poco confusa en algunas partes, pero en general es buena.",
    "Increible desarrollo de los personajes y la trama.",
    "Nada especial. Es una pelicula mas del monton.",
    "Un final perfecto para una gran pelicula.",
    "Simplemente aburrida. No la recomendaria.",
    "Buena pero no genial. Le falto algo para ser memorable.",
    "Un desastre. No puedo creer que haya perdido tiempo viendola.",
    "Bien hecha y con una buena historia. Me gusto.",
    "Cautivadora de principio a fin. Muy bien lograda.",
    "Para toda la familia. Una pelicula que todos pueden disfrutar.",
    "Una pelicula unica y diferente a lo que estamos acostumbrados.",
    "Demasiado dramatica para mi gusto. No la volveria a ver.",
    "Bien actuada y con un buen guion. Muy recomendable.",
    "Un placer verla. Disfrute cada minuto de la pelicula.",
    "Una experiencia visual impresionante. Muy bien lograda.",
    "Una perdida de tiempo. No entiendo las buenas criticas.",
    "Una historia bien contada y con personajes interesantes.",
    "Nada memorable. Es una pelicula olvidable.",
    "Sorprendentemente buena. Me gusto mas de lo que esperaba.",
    "No vale la pena. Hay mejores opciones para ver.",
    "Podria haber sido mejor. Le falto desarrollo.",
    "Un clasico instantaneo. Sera recordada por mucho tiempo.",
    "Demasiado exagerada en algunas partes. No me convencio.",
    "Llena de emociones y momentos inolvidables.",
    "Un viaje fantastico que te transporta a otro mundo.",
    "Un guion brillante y bien desarrollado.",
    "Demasiado cliche y predecible. Nada nuevo.",
    "No me atrapo en ningun momento. Un poco aburrida.",
    "Una buena adaptacion del libro. Me gusto.",
    "Entretenida pero olvidable. No creo que la vuelva a ver.",
    "Increiblemente inspiradora. Te deja pensando.",
    "Previsible en muchos aspectos, pero aun asi disfrutable.",
    "Una maravilla visual. Los efectos son de lo mejor.",
    "Me hizo llorar. Una historia muy emotiva.",
    "Demasiado simple para mi gusto. Esperaba mas.",
    "Una obra de arte. Cada escena es perfecta.",
    "Las actuaciones son mediocres. No me convencieron.",
    "Visualmente hermosa. Cada cuadro es una pintura.",
    "Una historia conmovedora que toca el corazon.",
    "Un espectaculo visual impresionante.",
    "No recomendada. Hay opciones mucho mejores.",
    "Una trama compleja y bien desarrollada.",
    "Una joya cinematografica que no te puedes perder.",
    "Una pelicula divertida y ligera.",
    "Demasiado intensa en algunas partes. Me agoto.",
    "Una pelicula poderosa y con un gran mensaje.",
    "Me aburrio en varias partes. No me gusto mucho.",
	"Una pelicula emocionante que te mantiene al borde de tu asiento. Las escenas de accion son impresionantes.",
    "No es para todos. Algunos podrian encontrarla aburrida, pero a mi me parecio fascinante.",
    "Una experiencia unica que no se puede describir con palabras. Hay que verla para entenderla.",
    "Demasiado rebuscada en algunos momentos, pero en general es una buena pelicula.",
    "Un clasico imperdible que todos deberian ver al menos una vez en la vida.",
    "Un desarrollo brillante de principio a fin. La trama es solida y bien estructurada.",
    "Llena de sorpresas y giros inesperados que mantienen al espectador enganchado.",
    "Visualmente creativa y muy bien lograda. Cada escena es una obra de arte.",
    "Falto desarrollo en algunos personajes, pero aun asi es una pelicula disfrutable.",
    "Muy impactante y conmovedora. Te deja pensando mucho tiempo despues de verla.",
    "Una comedia divertida que te hara reir de principio a fin. Muy recomendada.",
    "Un drama poderoso que toca temas profundos y te hace reflexionar.",
    "Llena de vida y color. Una pelicula que te llena de energia y buen humor.",
    "Una pelicula profunda y significativa. Muy bien realizada.",
    "Una gran aventura que te lleva a un viaje inolvidable. Perfecta para ver en familia.",
    "Un poco lenta en algunas partes, pero en general es una buena pelicula.",
    "Un deleite visual con una cinematografia impresionante. Muy recomendada.",
    "Una historia inspiradora que te motiva a seguir tus sueños. Muy emotiva.",
    "Llena de humor y momentos divertidos. Perfecta para pasar un buen rato.",
};

const char nombresUsuario [][DIM_USERNAME] = {
    "administrador",
    "JuanPerez",
    "MariaGomez",
    "CarlosRuiz",
    "AnaLopez",
    "PedroMartinez",
    "LauraHernandez",
    "JorgeGarcia",
    "CarmenSanchez",
    "JoseRamirez",
    "LuisFernandez",
    "ElenaDiaz",
    "RaulJimenez",
    "LuciaMoreno",
    "AlbertoCruz",
    "SofiaReyes",
    "MiguelTorres",
    "RosaCastro",
    "AngelOrtega",
    "AndreaRamos",
    "DavidVega",
    "MonicaMolina",
    "OscarGuerrero",
    "ClaraRomero",
    "JavierGomez",
    "PatriciaNunez",
    "VictorSantos",
    "IsabelOrtiz",
    "RicardoFlores",
    "PaulaMedina",
    "HectorSerrano",
    "AngelaLuna",
    "SergioDelgado",
    "CristinaPena",
    "ManuelRojas",
    "AliciaVargas",
    "FernandoLeon",
    "EvaGuzman",
    "DiegoMartinez",
    "MartaBenitez",
    "AdrianGil",
    "NataliaIglesias",
    "RobertoFuentes",
    "TeresaCampos",
    "JulianMendoza",
    "LorenaPascual",
    "MartinPerez",
    "JuliaEspinosa",
    "FranciscoSoto",
    "SilviaCarrasco",
    "PabloNavarro",
    "IreneDominguez",
    "JaimePrieto",
    "RocioSanchez",
    "GabrielHerrera",
    "BeatrizMarin",
    "FelipeVidal",
    "CarlaRubio",
    "IgnacioMorales",
    "EstherHidalgo",
    "RafaelCano",
    "SoniaBlanco",
    "AndresMoya",
    "VictoriaAguilar",
    "EmilioCampos",
    "DanielaSilva",
    "JulioLopez",
    "GloriaCabrera",
    "SamuelFerrer",
    "NuriaSantiago",
    "RodrigoLorenzo",
    "InesBermudez",
    "EduardoPardo",
    "LuisaGarrido",
    "RamiroEsteban",
    "PilarHerrero",
    "TomasGallego",
    "AriadnaSaez",
    "EstebanQuintero",
    "CeciliaMontero",
    "AntonioBravo",
    "ValeriaLozano",
    "AlvaroPeinado",
    "FabiolaRico",
    "MauricioPalacios",
    "ElisaAranda",
    "EliasDomingo",
    "VeronicaCalvo",
    "FedericoSanz",
    "CatalinaRivas",
    "MateoCordoba",
    "VanessaAndres",
    "AgustinVarela",
    "LorenaPino",
    "LeandroTrujillo",
    "AnaisDelgado",
    "LucasSuarez",
    "CarolinaDuran",
    "NicolasCrespo",
    "OlgaMiranda",
};

const char emails[][DIM_EMAIL] = {
    "admin@gmail.com",
    "JuanPerez@gmail.com",
    "MariaGomez@gmail.com",
    "CarlosRuiz@gmail.com",
    "AnaLopez@gmail.com",
    "PedroMartinez@gmail.com",
    "LauraHernandez@gmail.com",
    "JorgeGarcia@gmail.com",
    "CarmenSanchez@gmail.com",
    "JoseRamirez@gmail.com",
    "LuisFernandez@gmail.com",
    "ElenaDiaz@gmail.com",
    "RaulJimenez@gmail.com",
    "LuciaMoreno@gmail.com",
    "AlbertoCruz@gmail.com",
    "SofiaReyes@gmail.com",
    "MiguelTorres@gmail.com",
    "RosaCastro@gmail.com",
    "AngelOrtega@gmail.com",
    "AndreaRamos@gmail.com",
    "DavidVega@gmail.com",
    "MonicaMolina@gmail.com",
    "OscarGuerrero@gmail.com",
    "ClaraRomero@gmail.com",
    "JavierGomez@gmail.com",
    "PatriciaNunez@gmail.com",
    "VictorSantos@gmail.com",
    "IsabelOrtiz@gmail.com",
    "RicardoFlores@gmail.com",
    "PaulaMedina@gmail.com",
    "HectorSerrano@gmail.com",
    "AngelaLuna@gmail.com",
    "SergioDelgado@gmail.com",
    "CristinaPena@gmail.com",
    "ManuelRojas@gmail.com",
    "AliciaVargas@gmail.com",
    "FernandoLeon@gmail.com",
    "EvaGuzman@gmail.com",
    "DiegoMartinez@gmail.com",
    "MartaBenitez@gmail.com",
    "AdrianGil@gmail.com",
    "NataliaIglesias@gmail.com",
    "RobertoFuentes@gmail.com",
    "TeresaCampos@gmail.com",
    "JulianMendoza@gmail.com",
    "LorenaPascual@gmail.com",
    "MartinPerez@gmail.com",
    "JuliaEspinosa@gmail.com",
    "FranciscoSoto@gmail.com",
    "SilviaCarrasco@gmail.com",
    "PabloNavarro@gmail.com",
    "IreneDominguez@gmail.com",
    "JaimePrieto@gmail.com",
    "RocioSanchez@gmail.com",
    "GabrielHerrera@gmail.com",
    "BeatrizMarin@gmail.com",
    "FelipeVidal@gmail.com",
    "CarlaRubio@gmail.com",
    "IgnacioMorales@gmail.com",
    "EstherHidalgo@gmail.com",
    "RafaelCano@gmail.com",
    "SoniaBlanco@gmail.com",
    "AndresMoya@gmail.com",
    "VictoriaAguilar@gmail.com",
    "EmilioCampos@gmail.com",
    "DanielaSilva@gmail.com",
    "JulioLopez@gmail.com",
    "GloriaCabrera@gmail.com",
    "SamuelFerrer@gmail.com",
    "NuriaSantiago@gmail.com",
    "RodrigoLorenzo@gmail.com",
    "InesBermudez@gmail.com",
    "EduardoPardo@gmail.com",
    "LuisaGarrido@gmail.com",
    "RamiroEsteban@gmail.com",
    "PilarHerrero@gmail.com",
    "TomasGallego@gmail.com",
    "AriadnaSaez@gmail.com",
    "EstebanQuintero@gmail.com",
    "CeciliaMontero@gmail.com",
    "AntonioBravo@gmail.com",
    "ValeriaLozano@gmail.com",
    "AlvaroPeinado@gmail.com",
    "FabiolaRico@gmail.com",
    "MauricioPalacios@gmail.com",
    "ElisaAranda@gmail.com",
    "EliasDomingo@gmail.com",
    "VeronicaCalvo@gmail.com",
    "FedericoSanz@gmail.com",
    "CatalinaRivas@gmail.com",
    "MateoCordoba@gmail.com",
    "VanessaAndres@gmail.com",
    "AgustinVarela@gmail.com",
    "LorenaPino@gmail.com",
    "LeandroTrujillo@gmail.com",
    "AnaisDelgado@gmail.com",
    "LucasSuarez@gmail.com",
    "CarolinaDuran@gmail.com",
    "NicolasCrespo@gmail.com",
    "OlgaMiranda@gmail.com",
};

const char contrasenias[][DIM_PASSWORD] = {
    "Abc123",
    "HolaMundo2021",
    "Qwerty12345",
    "MiClaveSegura",
    "Carlos2021",
    "Abcd1234",
    "Segura2021",
    "Pelicula123",
    "ClaveSecreta1",
    "SuperUser1",
    "HolaAmigo123",
    "BuenosDias1",
    "SeguraClave1",
    "Estrella2021",
    "SolYMar123",
    "Contraseña1",
    "LlaveSegura1",
    "Estudiante21",
    "AmorYAmistad1",
    "PaisajeBonito1",
    "MiSecreto2021",
    "SuperClave1",
    "NocheEstrellada1",
    "ViajeSeguro1",
    "Montana1234",
    "MarYPlaya123",
    "Hola2021Clave",
    "RosaRoja123",
    "MiPrimavera1",
    "MusicaBuena1",
    "PeliculaBuena1",
    "HolaFamilia1",
    "ContraseñaBuena1",
    "ClaveDeOro1",
    "LlaveDePlata1",
    "ContraseñaTop1",
    "MiSuperClave1",
    "Bienvenido2021",
    "LlaveMagica1",
    "ClaveMagica1",
    "AmigosSiempre1",
    "FamiliaUnida1",
    "PeliculaTop1",
    "ViajeDeOro1",
    "ClaveGenial1",
    "ClaveEstrella1",
    "SuperPelicula1",
    "LlaveDelSol1",
    "ClaveDeLuna1",
    "LlaveDelMar1",
    "MontanaYMar1",
    "ContraseñaSol1",
    "MiPelicula2021",
    "MiLlaveSegura1",
    "ViajeDePlata1",
    "LlaveSegura21",
    "MiContraseña1",
    "Contraseña123",
    "Segura2022",
    "HolaSegura123",
    "LlaveDeVida1",
    "SuperViaje1",
    "AmorSegura1",
    "Hola2021Viaje",
    "ContraseñaLlave1",
    "LlaveDeAmor1",
    "HolaClave2021",
    "ViajeBonito1",
    "HolaPelicula1",
    "ClaveTop2021",
    "LlaveYClave1",
    "AmorYVida123",
    "MiLlaveBonita1",
    "PeliculaEstrella1",
    "LlaveYViaje1",
    "ContraseñaMagica1",
    "HolaLlave2021",
    "LlaveGenial2021",
    "ContraseñaVida1",
    "ClaveEstrella2021",
    "LlaveDeNoche1",
    "ViajeDeEstrella1",
    "ContraseñaSuper1",
    "SuperLlave2021",
    "ContraseñaLlave2",
    "HolaClave21",
    "ContraseñaViaje1",
    "LlaveSecreta21",
    "ContraseñaOro1",
    "ViajeDeOro21",
    "LlaveDeSol123",
    "LlaveDeNube1",
    "ContraseñaNube1",
    "ViajeDeSol1",
    "LlaveMagica21",
    "ClaveDeNube1",
    "ContraseñaTop2",
    "LlaveMagica2021",
    "MiLlaveDeOro1",
    "ClaveDeVida123",
};

const char calles [][DIM_CALLE] = {
    "San Martin",
    "Rivadavia",
    "Belgrano",
    "Moreno",
    "Bolivar",
    "25 de mayo",
    "Independencia"
};

const char ciudades [][DIM_CIUDAD] = {
    "Mechongue",
    "Mar del Plata",
    "Carlos Paz",
    "Rosario",
    "Necochea",
    "Miramar"
};

const char localidades [][DIM_LOCALIDAD] = {
    "Buenos Aires",
    "Cordoba",
    "Santa Fe",
    "Mendoza",
    "San Luis"
};

char paises [][DIM_PAIS] = {
    "Argentina",
    "Chile",
    "Paraguay",
    "Uruguay",
    "Brasil"
};

void cargarCalleRandom(char calle[]){
    int cantidadElementos = sizeof(calles)/DIM_CALLE;

    strcpy(calle, calles[rand()%cantidadElementos]);
}

void cargarEmailRandom(char email[]){
    int cantidadElementos = sizeof(emails)/DIM_EMAIL;

    strcpy(email, emails[rand()%cantidadElementos]);
}

void cargarCiudadRandom(char ciudad[]){
    int cantidadElementos = sizeof(ciudades)/DIM_CIUDAD;

    strcpy(ciudad, ciudades[rand()%cantidadElementos]);
}

void cargarLocalidadRandom(char localidad[]){
    int cantidadElementos = sizeof(localidades)/DIM_LOCALIDAD;

    strcpy(localidad, localidades[rand()%cantidadElementos]);
}

void cargarUsernameRandom(char username[]){
    int cantidadElementos = sizeof(nombresUsuario)/DIM_USERNAME;

    strcpy(username, nombresUsuario[rand()%cantidadElementos]);
}

void cargarPasswordRandom(char password[]){
    int cantidadElementos = sizeof(contrasenias)/DIM_PASSWORD;

    strcpy(password, contrasenias[rand()%cantidadElementos]);
}

void cargarPaisRandom(char pais[]){
    int cantidadElementos = sizeof(paises)/DIM_PAIS;

    strcpy(pais, paises[rand()%cantidadElementos]);
}

void cargarTituloComentarioRandom(char tituloComentario[]){
    int cantidadElementos = sizeof(titulosComentarios)/DIM_TITULO_COMENTARIO;

    strcpy(tituloComentario, titulosComentarios[rand()%cantidadElementos]);
}

void cargarDescripcionComentarioRandom(char descripcionComentario[]){
    int cantidadElementos = sizeof(descripcionComentarios)/DIM_DESCRIPCION_COMENTARIO;

    strcpy(descripcionComentario, descripcionComentarios[rand()%cantidadElementos]);
}

void cargarTituloPeliculaRandom(char tituloPelicula[]){
    int cantidadElementos = sizeof(titulosPeliculas)/DIM_TITULO_PELICULA;

    strcpy(tituloPelicula, titulosPeliculas[rand()%cantidadElementos]);
}

void cargarDirectorRandom(char director[]){
    int cantidadElementos = sizeof(directores)/DIM_DIRECTOR;

    strcpy(director, directores[rand()%cantidadElementos]);
}

void cargarEstudioRandom(char estudio[]){
    int cantidadElementos = sizeof(estudios)/DIM_ESTUDIO;

    strcpy(estudio, estudios[rand()%cantidadElementos]);
}

void cargarCategoriaRandom(char categoria[]){
    int cantidadElementos = sizeof(categorias)/DIM_CATEGORIA;

    strcpy(categoria, categorias[rand()%cantidadElementos]);
}

stPelicula cargarPeliculaRandom(int id){
    stPelicula pelicula;

    pelicula.idPelicula = id;

    if(id >= 0 && id < sizeof(titulosPeliculas)/ DIM_TITULO_PELICULA){
        strcpy(pelicula.titulo, titulosPeliculas[id]);
    }
    else{
        cargarTituloPeliculaRandom(pelicula.titulo);
    }

    cargarDirectorRandom(pelicula.director);
    cargarEstudioRandom(pelicula.estudio);
    cargarCategoriaRandom(pelicula.categoria);
    pelicula.valoracion = 0;
    pelicula.eliminado = 0;

    return pelicula;
}

void cargarFechaRandom(char * fecha){
    char aux[DIM_FECHA];
    char aux2[DIM_FECHA];

    int dia = rand()%28+1;
    int mes = rand()%12+1;
    int anio = rand()%105+1900;

    itoa(anio, aux, 10);
    strcat(aux, "/");

    itoa(mes, aux2, 10);
    strcat(aux, aux2);
    strcat(aux, "/");

    itoa(dia, aux2, 10);
    strcat(aux, aux2);

    strcpy(fecha, aux);
}

stComentario cargarComentarioRandom(){
    stComentario comentario;

    comentario.idComentario = rand();
    comentario.idPelicula = rand();
    comentario.idUsuario= rand();
    cargarTituloComentarioRandom(comentario.titulo);
    cargarDescripcionComentarioRandom(comentario.descripcion);
    comentario.puntaje = rand()%5+1;
    cargarFechaRandom(comentario.fechaComentario);
    comentario.eliminado = 0;

    return comentario;
}

stUsuario cargarUsuarioRandom(int id){
    stUsuario usuario;

    usuario.idUsuario = id;

    if(id >= 0 && id < sizeof(emails)/ DIM_EMAIL){
        strcpy(usuario.email, emails[id]);
        strcpy(usuario.username, nombresUsuario[id]);
        strcpy(usuario.password, contrasenias[id]);
    }
    else{
        cargarEmailRandom(usuario.email);
        cargarUsernameRandom(usuario.username);
        cargarPasswordRandom(usuario.password);
    }

    usuario.esAdmin = 0;
    usuario.genero = cargarGeneroRandom();
    cargarFechaRandom(usuario.fechaNacimiento);
    usuario.vFavoritos = 0;
    usuario.domicilio = cargarDomicilioRandom();
    cargarDniRandom(usuario.dni);
    usuario.eliminado = 0;

    return usuario;
}

void cargarDniRandom(char dni[]){
    // rand() no genera un numero lo suficientemente grande como para un DNI
    // Se multiplica el numero random para obtener un DNI de 7 u 8 cifras
    int num = rand() * 180+5000000;

    // Almacena el numero como string
    sprintf(dni, "%d", num);
}

char cargarGeneroRandom(){
    char genero;
    int num = rand()%CANT_GENEROS;

    switch(num){
        case 0:
            genero = 'm';
            break;
        case 1:
            genero = 'f';
            break;
        case 2:
            genero = 'x';
            break;
        default:
            genero = 'x';
            break;
    }

    return genero;
}

stDomicilio cargarDomicilioRandom(){
    stDomicilio domicilio;

    cargarCalleRandom(domicilio.calle);
    domicilio.altura = rand()%10000;
    domicilio.cp = rand()%10000;
    cargarCiudadRandom(domicilio.ciudad);
    cargarLocalidadRandom(domicilio.localidad);
    cargarPaisRandom(domicilio.pais);

    return domicilio;
}
