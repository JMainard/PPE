/*function passwordVerif()
{
	var mdp=document.getElementById("password").value;
	var mdpVerif=document.getElementById("passwordVerification").value;

	if (mdp !=mdpVerif && mdp.length <9)
		
		return false;
		alert("Mauvais mdp");	
	else
	{
		return true ;
	}

}*/



//alert("ploum");
function verification(champ)
{
 var inputChamp=document.getElementById(champ);
 if (inputChamp.value.length>1)
	{
		inputChamp.className="form-control is-valid";
	}
else
	{
		inputChamp.className="form-control is-invalid";
	}
}
function pwdVerification()
{
  //  alert("ploum2");
	var mdp=document.getElementById("password");
	var mdpMot=mdp.value ;
var anUpperCase=/[A-Z]/; //Déclaration des variables test pour savoir si il ya bien une maj un min ou un num
var aLowerCase=/[a-z]/; 
var aNumber=/[0-9]/;
	
	var numUpper=0;
    var numLower=0;
    var numNums=0;
    
    for(var rechercheLettreNum=0; rechercheLettreNum<mdpMot.length; rechercheLettreNum++){
        if(anUpperCase.test(mdpMot[rechercheLettreNum]))
            numUpper++;
        else if(aLowerCase.test(mdpMot[rechercheLettreNum]))
            numLower++;
        else if(aNumber.test(mdpMot[rechercheLettreNum]))
            numNums++;
	}

	if(numUpper<1 || numLower<1 || numNums<1 || mdp.length<8)
	{
		mdp.className="form-control is-invalid";
	}
else 
	{
		mdp.className="form-control is-valid";
	}
}

function pwdVerificationTest()
{
	mdp2=document.getElementById("passwordVerification").value;
 if (mdpMot==mdp2)
{
	mdp2.className="form-control is-valid";
}
else{
 mdp2=className="form-control is-invalid";
}
}

 	
