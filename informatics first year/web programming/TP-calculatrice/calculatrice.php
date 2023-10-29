
<!-- calculatrice.php -->

<html>
	<head>
		<meta charset="utf-8" />
		<title> Une petite calculatrice </title>
		<style type="text/css"> 
			H1.titre1 
			{
				border-style: solid; 
				border-width: 3px; 
				border-color: blue; 
				font-size: 30pt; 
				color: grey;
				margin : 0px 340px 0px 340px;
			}
			
			P.paragraphe1 
			{
				font-style: italic; 
				color: blue; 
				border-style: none; 
				background-color: #CFE2F6;
				font-size : 14pt;
				margin : 0px 340px 0px 340px;	
			}
			
			.paragraphe2 
			{
				color: blue; 
			    border-style: none; 
			    background-color: #CEEDF4;
			    margin : 0px 340px 0px 340px;
			    font-size : 15pt;
			}
			
			.div1 
			{
				border-style: none; 
				border-radius: 30pt 30pt 30pt 30pt; 
				background-color: #2E9BFF; 
				color: white; 
				font-size: 24pt;
				margin : 0px 340px 0px 340px;
				padding : 1px 0px 1px 0px;
			}
			.div2
			{
				border-style: none;
				background-color: #CEEDF4
				color : blue;
				margin : 0px 350px 0px 350px;
			}
					
		</style>
	</head>
            
	<body>
		<center>
			<h1 class="titre1"> Calculatrice </h1>
			
			<br/>
			
			<p class="paragraphe1"> Une petite calculatrice minimaliste pour pratiquer la programmation web ! <br/> 
			Vous ne pouvez faire qu'une opération entre deux nombres. </p>
			
			<br/>
				
			<div class="div1">
				<form method="GET" action="calculatrice.php">
					<p> Entrer deux nombres de l'opération choisie : <br/> <br/> <br/>
					nombre1 : <input type="text" name="nombre1" value="Entrez un nombre" size="20" maxlength="20" /> <br/> <br/>
					<select name="choix">
						<option value="plus" SELECTED>+</option>
						<option value="moins">-</option>
						<option value="fois">*</option>
						<option value="divisé">/</option>
					</select>	<br/> <br/>
					nombre2 : <input type="text" name="nombre2" value="Entrer un nombre" size="20" maxlength="20" /> </p>
						
					<input type="submit" name="action" value="calculer" /> <br/>
						
					<div>
					
					<?php
					function calculatrice ($nb1, $nb2, $op)
					{
					if(is_numeric($nb1) && is_numeric($nb2))
					{
					if($op === "plus") {echo ($nb1+$nb2);}
					else if ($op === "moins") {echo ($nb1-$nb2);}
					else if ($op === "fois") {echo ($nb1*$nb2);}
					else if ($op === "divisé") {echo ($nb1/$nb2);}
					}
					}
				
                    if(isset ($_GET['nombre2']) && isset($_GET['nombre2']))
					{
					echo "le resultat de "; echo $_GET['nombre1']; echo " "; echo $_GET['choix']; echo " "; echo $_GET['nombre2']; echo " est "; echo calculatrice ($nb1, $nb2, $op) ;
				    }	
					?>
					</div>
						
					</form>
						
				</div>
						
			</center>	
				
				<br/>
				
		<p class = "paragraphe2"> Les paramètres transmis au serveur via le formulaire sont : <br/>
		<?php
		foreach($_GET as $k=> $v) { echo "$k : $v<br />\n"; }
		?></p>
			
	</body>
	
</html>	
