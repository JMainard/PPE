-- Jeux d'essai  pour test administrateur
-- créer le 18-09-2019 par J.Mainard

-- Suppression des tables des jeux d'essai
/*delete from producteur;
delete from administrateur;
delete from role;
delete from utilisateur;
delete from annonceVente;
delete from uniteMesure;*/

--Création des jeux d'essais

insert into role values
(1,'Producteur','connexion au site et ajout de produit à vendre',NULL),
(3,'administrateur','Back Office',NULL),
(4,'super-admin','back offfice',NULL);

insert into utilisateur values
(1,4,'Jeremy','Mainard','','','','admin','21232f297a57a5a743894a0e4a801fc3','mainard17@outlook.fr','',1,NULL),
(2,1,'Yohan','Salamone','','','','yoyodu05','','mainard17@outlook.fr','',1,NULL),
(3,1,'Valentine','Casse','','','','valocheDuNord','','mainard17@outlook.fr','',1,NULL);

insert into administrateur values
(1,1);


insert into producteur values
(1,'Homme','FraiseRouge','12345017859634','02 54 78 96 32','06 24 85 67 35',2),
(2,'Femme','Bettereve','1789650234856','02 58 69 32 14','06 47 85 63 41',3);

insert into uniteMesure values
(1,'KG'),
(2,'Barquette 250g'),
(3,'Barquette 500g'),
(4,'Sachet 1.5 kg'),
(5,'A la botte');

insert into annonceVente values
(1,1,1,'Tomate ','Grappe d\'Espagne','Fruit',50.5,'',2.10,1.60,2.10,'2019-10-10',NULL,NULL),
(2,3,2,'Fraise','Kermenec, Bretagne','Fruit',10.2,'',3.10,1.15,1.55,'2019-12-25',NULL,NULL);


insert into mail values
(1,'mainard17@outlook.fr','TestMail1','Ceci est le premier mail d une longue serie'),
(2,'mainard17@outlook.fr','TestMail2','Deuxieme test'),
(3,'mainard17@outlook.fr','TestMail3','LE TROISIEME');
