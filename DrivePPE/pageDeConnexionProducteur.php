<?php
session_start();
include('connect.php');
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
<link rel="stylesheet" type="text/css" href="cssPageConnexion.css" />
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <title> Connexion </title>
  </head>

<body>
 <div class="container">
    <div class="row">
      <div class="col-sm-9 col-md-7 col-lg-5 mx-auto">
        <div class="card card-signin my-5">
          <div class="card-body">
            <h5 class="card-title text-center">Sign In</h5>
            <form method="POST" class="form-signin" action="">
              <div class="form-label-group">
                <input type="text" id="inputId" class="form-control" name="id" placeholder="Identifiant" required autofocus>
                <label for="inputId">Identifiant</label>
              </div>

              <div class="form-label-group">
                <input type="password" id="inputPassword" class="form-control"  name="pwd" placeholder="Password" required>
                <label for="inputPassword">Mot de Passe</label>
              </div>

              <div class="custom-control custom-checkbox mb-3">
                <input type="checkbox" class="custom-control-input" id="customCheck1">
                <label class="custom-control-label" for="customCheck1">Remember password</label>
              </div>
              <button class="btn btn-lg btn-primary btn-block text-uppercase" type="submit" >Sign in</button>
              <hr class="my-4">
			  	<a href="formulaireProducteur.html">
	 			<button type="button" class="btn btn-warning">Pas encore inscrit ?</button>
				</a>
            </form>
          </div>
        </div>
      </div>
    </div>
  </div>




    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>

<?php
//Test pour savoir si l'id le mdp et la confirmation mail sont ok si oui on le connecte sinon message d'authentification incorrecte .
if(isset($_POST['id'])&&isset($_POST['pwd']))
	{
		$_SESSION['id']=$_POST['id'];
		$_SESSION['pwd']=$_POST['pwd'];
		//Comparaison a la base de donnée
		$requete="select prodLogin,prodMdp,mailVerif from Producteur where prodLogin='".$_SESSION['id']."'";
		$res=mysqli_query($maBase,$requete);
		$tabInfos=mysqli_fetch_row($res);
		if($_SESSION['id']==$tabInfos[0]&&md5($_SESSION['pwd'])==$tabInfos[1]&&$tabInfos[2]==1)
		{
			header('location:pageProducteur.php');
		}
		else
		{
			echo 'Authentification incorrecte, veuillez réessayer.';
		}
	}

?>
