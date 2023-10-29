<!-- 2048.php -->

<?php require_once 'fonctions-2048.php'; ?>
<link rel="stylesheet" type="text/css" href="styles2048.css" />

<html> 
	
	<head>
	 	<meta charset="utf-8" />					
		<title>2048</title>
		
		<style type="text/css">
		
	    .title
		{ 
			color : white;
			font-size : 20pt; 
			border-style : none; 
			border-radius : 15pt 15pt 15pt 15pt;
			background-color : #F7D358; 
			margin : 0px 570px 0px 570px;
			font-family: sans-serif;
		}
		
		.rules
		{
			border-style : solid;
			border-width : 0px 10px 0px 10px;
			border-color : #A4A5A5;
			padding : 5px;
			border-radius : 10pt 10pt 10pt 10pt;
			font-style : italic;
			background-image: linear-gradient(to right, #E3A8F3, #E1F4A8);
		}
		
	    .button
		{
			color : black;
			border-style : solid;
			background-color : #F7D358;
			border-radius : 3pt 3pt 3pt 3pt;
			font-family: cursive;
		}
		
		.cell 
		{
			width:100px;
		    height:100px;
		    background-color : grey;
		    text-align: center;
		    border: 5px solid #1C1C1C;
		    font-size : 20pt;
		    font-family: cursive;
		}
		
		.table 
		{
			border-collapse: collapse; 
		}
		
		
		.score 
		{
			border-style : outset;
			margin : 0px 550px 0px 550px;
			font-family: cursive;
			animation-name : changeColor;
			animation-duration : 10s;
			animation-iteration-count: infinite;
		}
		
		@keyframes changeColor 
		{
			25%  {background-color: #F68081;}
			50%  {background-color: #F2F681;}
			75%  {background-color: #81BEF7;}
			100% {background-color: #80F780;}
		}

		.background 
		{
			background-image: url("https://cdn.pixabay.com/photo/2016/10/13/00/22/illustration-1736462_1280.png");
		}
		
		.cell2
		{
			width:100px;
		    height:100px;
		    background-color : #eeed4a;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell4
		{
			width:100px;
		    height:100px;
		    background-color : #ede0c8;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell8
		{
			width:100px;
		    height:100px;
		    background-color : #f2b179;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell16
		{
			width:100px;
		    height:100px;
		    background-color : #f59563;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell32
		{
			width:100px;
		    height:100px;
		    background-color : #f67c5f;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell64
		{
			width:100px;
		    height:100px;
		    background-color : #f65e3b;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell128
		{
			width:100px;
		    height:100px;
		    background-color : #edcf72;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell256
		{
			width:100px;
		    height:100px;
		    background-color : #edcc61;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell512
		{
			width:100px;
		    height:100px;
		    background-color : #edc850;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell1024
		{
			width:100px;
		    height:100px;
		    background-color : #edc53f;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
	    
	    .cell2048
		{
			width:100px;
		    height:100px;
		    background-color : #edc22e;
		    text-align: center;
		    border: 5px solid #1C1C1C;;
		    font-size : 20pt;
		    font-family: cursive;
	    }
		
		</style>
		
</script>

		
		<!-- --------------------
		
		Fonctions-2048.php
		
		--------------------- -->
		
		<?php
		
         if(isset ($_GET['action-joueur']))
         {
			 
			 if($_GET['action-joueur'] == "Nouvelle partie")
			 {
				 nouvelle_partie();
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
             }
		     
			 if($_GET['action-joueur'] == "Left")
             {
				 update_fichier_vers_matrice();
				 for($i=0; $i<4; $i++)
				 {
					 decale_ligne_gauche($i);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
				 for($j=0; $j<4; $j++)
				 {
					 fusion_ligne_gauche($j);
					 $score = file_get_contents('score.txt');
					 file_put_contents('score.txt', $score);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
				 
			     if(grille_pleine() != true)
			     {
			     place_nouveau_nb();
		         }
			     update_matrice_vers_fichier_blank();
			     update_matrice_vers_fichier();		 
		     }
		     
		     if($_GET['action-joueur'] == "Right")
		     {
				 update_fichier_vers_matrice();
				 for($i=0; $i<4; $i++)
				 {
					 decale_ligne_droite($i);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
				 for($j=0; $j<4; $j++)
				 {
					 fusion_ligne_droite($j);
					 $score = file_get_contents('score.txt');
					 file_put_contents('score.txt', $score);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
				 
				 if(grille_pleine() != true)
			     {
			     place_nouveau_nb();
		         }
			     update_matrice_vers_fichier_blank();
			     update_matrice_vers_fichier();	
			 }
			 
			 if($_GET['action-joueur'] == "Up")
		     {
				 update_fichier_vers_matrice();
				 for($i=0; $i<4; $i++)
				 {
					 decale_col_haut($i);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice(); 
				 for($j=0; $j<4; $j++)
				 {
					 fusion_col_haut($j);
					 $score = file_get_contents('score.txt');
					 file_put_contents('score.txt', $score);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
				 
				 if(grille_pleine() != true)
			     {
			     place_nouveau_nb();
		         }
			     update_matrice_vers_fichier_blank();
			     update_matrice_vers_fichier();	
			 }
			 
			 if($_GET['action-joueur'] == "Down")
		     {
				 update_fichier_vers_matrice();
				 for($i=0; $i<4; $i++)
				 {
					 decale_col_bas($i);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice(); 
				 for($j=0; $j<4; $j++)
				 {
					 fusion_col_bas($j);
					 $score = file_get_contents('score.txt');
					 file_put_contents('score.txt', $score);
				 }
				 update_matrice_vers_fichier_blank();
				 update_matrice_vers_fichier();
				 
				 update_fichier_vers_matrice();
				 
				 if(grille_pleine() != true)
			     {
			     place_nouveau_nb();
		         }
			     update_matrice_vers_fichier_blank();
			     update_matrice_vers_fichier();	
			 }
			 
        }
		?>
		
	<!-- --------------------
		
	Head 2048.php
		
	--------------------- -->
			
	</head>
	
	<body class="background"> 
		<center>
		
		<h1 class="title"> 2048 </h1>
		
		<p class="rules">
		Le but du jeu est de faire glisser des tuiles sur une grille, pour combiner les tuiles de mêmes valeurs et créer ainsi une tuile portant le nombre 2048. <br/>
		Le joueur peut toutefois continuer à jouer après cet objectif atteint pour faire le meilleur score possible. <br/>
		Le jeu se présente sous la forme d'une grille 4*4. Au début de la partie, deux cases contiennent un chiffre (2 ou 4). 
		Les nombres peuvent se déplacer à droite, à gauche, en haut ou en bas. 
		Quand deux cases de même valeur se rencontrent, elles fusionnent en une case qui vaut la somme des 2 cases fusionnées.
		Après chaque action du joueur, une nouvelle case apparaît avec pour valeur 2 ou 4. 
		Le but est donc d'obtenir une case valant 2048 avant que la grille ne soit pleine et qu'aucun mouvement 
		ne soit plus possible. 
		Si plus aucun mouvement n'est possible, la partie est perdue.
		</p>
		
		<form name="2048" method="GET" action="2048.php">
		<input class="button" type="submit" name="action-joueur" value="Nouvelle partie" />
		</form>
		
		<table class="table">
			<tr>
			    <td class="cell"> <?php echo $grille[0][0]; ?> </td>
				<td class="cell"> <?php echo $grille[0][1]; ?> </td>
				<td class="cell"> <?php echo $grille[0][2]; ?> </td>
				<td class="cell"> <?php echo $grille[0][3]; ?> </td>
			</tr>
			
			<tr>
				<td class="cell"> <?php echo $grille[1][0]; ?> </td>
				<td class="cell"> <?php echo $grille[1][1]; ?> </td>
				<td class="cell"> <?php echo $grille[1][2]; ?> </td>
			    <td class="cell"> <?php echo $grille[1][3]; ?> </td>
			</tr>
			
			<tr>
				<td class="cell"> <?php echo $grille[2][0]; ?> </td>
				<td class="cell"> <?php echo $grille[2][1]; ?> </td>
				<td class="cell"> <?php echo $grille[2][2]; ?> </td>
				<td class="cell"> <?php echo $grille[2][3]; ?> </td>
			</tr>
			
			<tr>
				<td class="cell"> <?php echo $grille[3][0]; ?> </td>
				<td class="cell"> <?php echo $grille[3][1]; ?> </td>
				<td class="cell"> <?php echo $grille[3][2]; ?> </td>
				<td class="cell"> <?php echo $grille[3][3]; ?> </td>
			</tr>
		</table>
		
		<br/>
		
		<form name="2048" method="GET" action="2048.php">
		<div>
		<input class="button" type="submit" name="action-joueur" value="Up" /> <br/>
		<input class="button" type="submit" name="action-joueur" value="Left" />
		<input class="button" type="submit" name="action-joueur" value="Down" />
		<input class="button"type="submit" name="action-joueur" value="Right" />
		</div>
		</form>
		
		<p class="score">
		<?php
		$score = file_get_contents('score.txt');
		echo "SCORE = "; echo $score;
		?>
		</p>
		
		<p class="rules">
		Aller vers le site web de
		<a  target="_blank" href="">info</a>
		ou bien
		<a  href="">recharger la page</a>
		.
		</p>
		
<div>

<?php 
		
affiche_sept_variables();
writelogs();

?>

</div>
	
		</center>
	</body> 
	
</html>
