<html>
<head>
<?php
	session_start();
	include("bdd.php");
	if (!$_SESSION["loggued_on_user"])
		header('Location: index.php');
	// $_SESSION["loggued_on_user"] = "emil";
	$_SESSION["gameid"] = 1337;
?>
<link rel="stylesheet" type="text/css" href="lobby/chat.css">
<link rel="stylesheet" type="text/css" href="star.css">
<!-- <link rel="stylesheet" type="text/css" href="index_style.css"> -->
<script src="//code.jquery.com/jquery-1.11.2.min.js"></script>
<script src="form.js"></script>
<script src="lobby/chat.js"></script>
<title>Lobby</title>
</head>
<body>

	<div class="form">
      
      <ul class="tab-group">
        <li class="tab active"><a href="#create_game">Create Game</a></li>
        <li class="tab"><a href="#join_game">Join Game</a></li>
      </ul>
      
      <div class="tab-content">
        <div id="create_game">   

          <h1>Create Game</h1>
        <?php
          echo "	<form action='create_game.php' method='POST'>	";
        ?>
          <div class="top-row">
            <div class="field-wrap">
              <label>
                Game ID<span class="req">*</span>
              </label>
              <input type="text" name="game_id" required autocomplete="off" />
            </div>
          </div>
          
          <button type="submit" name="create_game" value="Create_game" class="button button-block"/>Let's Go !</button>
          
          </form>

        </div>
        
        <div id="join_game">   
          <h1>Join Game</h1>
        <?php
          echo "	<form action=".$_SERVER['PHP_SELF']." method='POST'>	";
        ?>
            <div class="field-wrap">
            <label>
              Game ID<span class="req">*</span>
            </label>
            <input type="text" name="game_id" required autocomplete="on"/>
          </div>
          
          <button type="submit" name="join_game" value="Join_game" class="button button-block"/>GL & HF</button>
          
          </form>

        </div>
        
      </div>

	</div><!-- form -->

	<div id="chat">
	  <h1>Lobby Chat</h1>
	  	<div id="chatlogs_box">
			<div id='chatlogs'>
			  LOADING CHATLOGS PLEASE WAIT...
			</div>
		</div>
		<div id='chatInput'>
		  <form name='form1'>
		    <textarea name='msg'></textarea><br />
		    <?php
			  $user = '"'.$_SESSION['loggued_on_user'].'"';
			  echo "	<a href='#' onclick='submitChat(".$user.")'>Send Message </a><br /><br /> ";
		    ?>
		  </form>
		</div>
    <?php display_delog(); ?>
	</div>

  <div class="stars"></div>
  <div class="twinkling"></div>

</body>
</html>