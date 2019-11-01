<?php
session_start();
include("connect.php");
//Déclaration des variables  pour verifieer les donnée rentre pdnas le form
$genre=$_POST['genre'];
$prenom=$_POST['prenom'];	
$nom=$_POST['nom'];	
$companyName=$_POST['companyName'];	
$companyRegister=$_POST['companyRegister'];	
$phoneNumber=$_POST['phoneNumber'];	
$phoneNumberMobile=$_POST['phoneNumberMobile'];	
$city=$_POST['city'];	
$postCode=$_POST['postCode'];	
$address=$_POST['address'];	
$email=$_POST['email'];	
$login=$_POST['login'];	
$password=md5($_POST['password']);	
$passwordVerification=$_POST['passwordVerification'];	
$submit=$_POST['submit'];
// ---- //
// Variable de comp pour savoir si toutes les conditions sont operationnelle
	$compteur=0;
// ---- //  
//print_r($_POST);
	
	//Série de test pour savoir si tous les conditions on était respecté
		//Boucle if pour savoir que chaque champ contien quelque chose 
	if (!empty($prenom)&& !empty($nom)&& !empty($companyName)&& !empty($companyRegister)&& !empty($phoneNumber)&& !empty($phoneNumberMobile)&& !empty($city)&& !empty($postCode)&& !empty($address)&& !empty($email)&& !empty($login)&& !empty($password)&& !empty($passwordVerification)&& !empty($genre))
	{
	//	echo 'Le champ est bien rempli';
		$compteur++;
		$identifiant=time();
	}
	else 
	{
		header('location:formulaireProducteur.html');
		
	}
	// ---- //
	//Fonction de verif des conditions du mot de passe 
	
	function passwordTest($password) { 
		$lettreMaj=0;
		$lettreMin=0;
		$num=0;
		$longueurPassword =strlen($password); //Savoir longuer du mdp

	 for ($noCase=0; $noCase<$longueurPassword; $noCase++)
		{$_POST['password'];



			$caractere=$password[$noCase];

			if ($caractere>='A' && $caractere<='Z')
			{
				$lettreMaj=1;
			}
			if ($caractere>='a' && $caractere<='z')
			{
				$lettreMin=1;
			}
			if ($caractere>='0' && $caractere<='9')
			{
				$num=1;
			}

		}
			$passwordCorrect=$num+$lettreMin+$lettreMaj;
			return $passwordCorrect;
 		}
// Test de savoir si le mdp est sup a 3 si oui les 3 condition sont correcte 
		$verifPassword=passwordTest($password);
	if ($verifPassword=3)
	{
			 $compteur++;
	}	
	else
	{
		header('location:formulaireProducteur.html');
	}		
	// ---- //
	
	// Gestion d'envoi des données du formulaire dans la base de données 
	// Traitement de l'ajout d'un animal
	if(isset($_POST['submit'])) {
		echo "Je vais tenter d'ajouter les infomations d'un producteur : ";
		echo $identifiant." ".$_POST['genre']." ".$_POST['prenom']." ".$_POST['nom']." ".$_POST['companyName']." ".$_POST['companyRegister']." ".$_POST['phoneNumber']." ".$_POST['phoneNumberMobile']." ".$_POST['city']." ".$_POST['postCode']." ".$_POST['address']." ".$_POST['email']." ".$_POST['login']." ".$password." ";
	// --- //
 // Génération de la clef
srand(time(NULL));
 $clef=(rand());
	echo $clef;
// --- //
// Envoi du mail
 $from='jmainard@btsinfogap.org';

$subject='Deolia validation de votre email'; 
http://172.29.56.14/~jmainard/DrivePPE/pageDeVerification.php?key='.md5($clef).'&&id='.$id.
$to=$email;

$message='Cliquez sur le lien pour valider votre inscription  http://172.29.56.14/~jmainard/DrivePPE/pageDeVerification.php?key='.md5($clef).'&&id='.$identifiant;
echo $message;

$headers='From: '.$from;

if ( mail($to,$subject,$message,$headers))
	{
		echo 'mail envoye';
	}
	else {
			echo ' pas envoyé';
		}

	// --- //

	//preparation de la requete d'insertion 
	$requete="insert into Producteur (prodId, prodGenre, prodPrenom, prodNom, prodNomEntreprise, prodNumSiret, prodNumFixe, prodNumMobile, prodVille, prodCP, prodAdresse, prodEmail, prodLogin, prodMdp, prodCleVerifMail) values ($identifiant,'".$_POST['genre']."','".$_POST['prenom']."','".$_POST['nom']."','".$_POST['companyName']."','".$_POST['companyRegister']."','".$_POST['phoneNumber']."','".$_POST['phoneNumberMobile']."','".$_POST['city']."','".$_POST['postCode']."','".$_POST['address']."','".$_POST['email']."','".$_POST['login']."','".$password."','".$clef."');";
	if ($maBase->query($requete))
{
echo " ok requete envoyé";
$_SESSION['id']=$identifiant;
$_SESSION['clef']=$clef;
}

else
{
echo "non";
echo $requete;
}
}	
	// --- // 

?>
