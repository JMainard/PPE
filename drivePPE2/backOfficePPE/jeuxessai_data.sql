-- Jeux d'essai  pour test administrateur
-- créer le 18-09-2019 par J.Mainard

-- Suppression des tables des jeux d'essai
delete from role;
delete from administrateur;

--Création des jeux d'essais

insert into role values
(1,'Producteur','connexion au site et ajout de produit aa vendre'),
(3,'administrateur','Back Office'),
(4,'super-admin','back offfice'),

insert into administrateur values
(1,4,'admin','21232f297a57a5a743894a0e4a801fc3','mainard17@outlook.fr');

