#include <stdio.h>
#include <stdlib.h>
#include "categorie.h"

Categorie Quotidien = {"Vie Quotidienne"};
SousCategorie Alimentation = {"Alimentation", Quotidien};
SousCategorie Habillement = {"Habillement", Quotidien};
SousCategorie Retrait = {"Retrait", Quotidien};
SousCategorie MaBanque = {"Ma Banque", Quotidien};
SousCategorie Divers = {"Divers", Quotidien};

Categorie Loisirs = {"Loisirs"};
SousCategorie Culture = {"Culture", Loisirs};
SousCategorie Presse = {"Presse", Loisirs};
SousCategorie RS = {"Restaurants & Sorties", Loisirs};
SousCategorie WV = {"Week-ends & Vacances", Loisirs};
SousCategorie Cadeaux = {"Cadeaux", Loisirs};
SousCategorie Divers = {"Divers", Loisirs};

Categorie Sante = {"Sant�"};
SousCategorie Medecins = {"M�decins", Sante};
SousCategorie Pharmacie = {"Pharmacie", Sante};
SousCategorie Secu = {"S�curit� Sociale & Mutuelle", Sante};
SousCategorie Divers = {"Divers", Sante};

Categorie Habitation = {"Habitation"};
SousCategorie Loyer = {"Loyer", Habitation};
SousCategorie GE = {"Gaz & Electricit�", Habitation};
SousCategorie Eau = {"Eau", Habitation};
SousCategorie TI = {"T�l�phonie & Internet", Habitation};
SousCategorie Assurances = {"Assurances", Habitation};
SousCategorie Divers = {"Divers", Habitation};

Categorie Transports = {"Transports"};
SousCategorie Abonnements = {"Abonnements", Transports};
SousCategorie Billets = {"Billets", Transports};
SousCategorie Parking = {"Parking", Transports};
SousCategorie Carburant = {"Carburant", Transports};
SousCategorie Entretien = {"Entretien", Transports};
SousCategorie Assurances = {"Assurances", Transports};
SousCategorie Divers = {"Divers", Transports};

Categorie IS = {"Imp�ts & Solidarit�"};
SousCategorie IR = {"Imp�ts sur le revenu", IS};
SousCategorie TF = {"Taxes Fonci�res", IS};
SousCategorie TH = {"Taxe d'habitation", IS};
SousCategorie Dons = {"Dons", IS};
SousCategorie Divers = {"Divers", IS};

Categorie Professionnel = {"Professionel"};
SousCategorie Materiel = {"Mat�riel", Professionnel};
SousCategorie Repas = {"Repas", Professionnel};
SousCategorie Voyages = {"Voyages", Professionnel};
SousCategorie Divers = {"Divers", Professionnel};

Categorie Epargne = {"Epargne"};

Categorie Divers = {"Divers"};
