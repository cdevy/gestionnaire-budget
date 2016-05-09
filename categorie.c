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

Categorie Sante = {"Santé"};
SousCategorie Medecins = {"Médecins", Sante};
SousCategorie Pharmacie = {"Pharmacie", Sante};
SousCategorie Secu = {"Sécurité Sociale & Mutuelle", Sante};
SousCategorie Divers = {"Divers", Sante};

Categorie Habitation = {"Habitation"};
SousCategorie Loyer = {"Loyer", Habitation};
SousCategorie GE = {"Gaz & Electricité", Habitation};
SousCategorie Eau = {"Eau", Habitation};
SousCategorie TI = {"Téléphonie & Internet", Habitation};
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

Categorie IS = {"Impôts & Solidarité"};
SousCategorie IR = {"Impôts sur le revenu", IS};
SousCategorie TF = {"Taxes Foncières", IS};
SousCategorie TH = {"Taxe d'habitation", IS};
SousCategorie Dons = {"Dons", IS};
SousCategorie Divers = {"Divers", IS};

Categorie Professionnel = {"Professionel"};
SousCategorie Materiel = {"Matériel", Professionnel};
SousCategorie Repas = {"Repas", Professionnel};
SousCategorie Voyages = {"Voyages", Professionnel};
SousCategorie Divers = {"Divers", Professionnel};

Categorie Epargne = {"Epargne"};

Categorie Divers = {"Divers"};
