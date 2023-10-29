<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

<!DOCTYPE html> 

<!-- ---------------
		
php de res.php
		
---------------- -->

<?php 

require_once 'fonction-res.php'; 
require_once '../../LIB/librairie-res.php';

global $auteur;

$auteur = retourne_auteur();

if(!empty($_POST['post_msg']))
{
	if($_POST['action'])
	{
		//ajout_post_msg();
	}
}

?>

<!-- ---------------
		
head de res.php
		
---------------- -->

<html class="background"> 
	<head> 
		<meta charset="utf-8" /> 
		<title>
			Le réseau social de LIFASR2
		</title>
		<style type="text/css">
			
		</style>
	</head> 
	
	<!-- ---------------
		
	body de res.php
		
	---------------- -->
	
	<body class="background">
		
		<div class="menu">
			
			<p class="affichage"> > Trier l'affichage < </p>
			
			<p class="message">
			<input type="checkbox" name="cours1" value="1" checked /> Images
			<br/> <br/>
			<input type="checkbox" name="cours1" value="2" checked /> Messages
			<br/> <br/>
			<input type="radio" name="cours2" value="1" checked /> Avec commentaires
			<br/> <br/>
			<input type="radio" name="cours2" value="2" /> Sans commentaires
			<br/> <br/>
			</p>

			<p class="message">
			Nombres de posts à afficher :
			<select name="menu" class="message">
            <option value="v1">1</option>
            <option value="v2" SELECTED>2</option>
            <option value="v3">3</option>
            </select>
            <br/> <br/>
            </p>
	     
	        <p> <center>
            <input type="submit" name="action-joueur" value="Afficher" class="button3" />
            </center> </p>
            
            </div>
		
        <!-- ---------------
		
		contenu de res.php
		
		---------------- -->
		
		<div class="contenu">
			
		<!-- ---------------
		
		nouveau_post de res.php
		
		---------------- -->
			
		<div class="nouveau_post">
			
			<p class="title"> > Bonjour <?php echo " "; echo $auteur; echo" ! "; ?> < </p>
			
			<p class="message2"> 
				
			Aller vers le site web de
            <a class="highlight"  target="_blank" href="">info</a>
            ou bien
            <a class="highlight" href="">recharger la page</a>.
			</p>
			
			<form name="nouveau_post" method="POST" action="res.php" enctype="multipart/form-data">
				
		        <textarea name="post_msg" rows="5" cols="90" placeholder="Quoi de neuf ?"></textarea>
		        
		        <br/> <br/>
				
				<!-- <input type="file" name="post_img">
				
				<input type="hidden" name="post_img" value="500000" /> -->
				
				<br/> <br/>
				
				<input class="button" type="submit" name="action" value="Poster" /> 
				
			</form>
			
		</div>
		
		<!-- ---------------
		
		affiche_post de res.php
		
		---------------- -->
		
		<?php if(!empty($_POST['post_msg']))
			{	?>
				
		<div class="affiche_post">
			
			<p class="message"> <?php
			
			echo "Message écrit par " . $auteur . " le " . date("Y-m-d") . " à " . date("H:i:s") . " : " 
					
			?> </p>  
					
		    <?php
		    
			echo $_POST['post_msg'];
					
			?>
			
			<br/>
			
			<form name="nouveau_post" method="POST" action="res.php" enctype="multipart/form-data">
				
				<input class="button2" type="submit" name="aime_msg" value="Aimer" /> <?php $nbLike = 0; echo $nbLike;?> <i class="glyphicon glyphicon-thumbs-up"></i>
				<input class="button2" type="submit" name="comment_msg" value="Commenter" />
					
				<br/> <br/> 
					
				<textarea name="post_msg" rows="3" cols="45" placeholder="Ajouter un commentaire !"></textarea>
			</form>
			
		<?php } ?>
		
		</div>
		
		<div class="affiche_post2"> <!-- AFFICHE LE MESSAGE D'UN FICHIER DONNÉ -->
			
			<p class="message"> <?php
			
			$tab = affiche_post('315-msg.txt');
			
			echo "Message écrit par " . $tab[2] . " ( ". $tab[3] . " ) : ";
					
			?> </p>  
					
		    <?php
		    
			echo $tab[6];
					
			?>
			
			<br/>
			
			<form name="nouveau_post" method="POST" action="res.php" enctype="multipart/form-data">
				
				<input class="button2" type="submit" name="aime_msg" value="Aimer" /> <?php $nbLike = 0; echo $nbLike;?> <i class="glyphicon glyphicon-thumbs-up"></i>
				<input class="button2" type="submit" name="comment_msg" value="Commenter" />
					
				<br/> <br/> 
					
				<textarea name="post_msg" rows="3" cols="45" placeholder="Ajouter un commentaire !"></textarea>
			</form>
		
		</div>
		
	</body>
</html> 
