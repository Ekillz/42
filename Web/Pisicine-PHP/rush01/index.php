<?php
session_start();

include('form.php');
include('bdd.php');
check_register();

if ($_POST['log'] === 'Connexion' && !$_SESSION['loggued_on_user']) {
	if (auth($_POST['login'], $_POST['password'])) {
		$_SESSION['loggued_on_user'] = $_POST['login'];
		echo "logué";
	}
}
is_log();
?>

<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8"
	<title>Index</title>
	<link rel="stylesheet" type="text/css" href="star.css">
	<link rel="stylesheet" type="text/css" href="index_style.css">
	<script src="//code.jquery.com/jquery-1.11.0.min.js"></script>
	<script src="form.js"></script>
</head>
<body>
	
	<div class="form">
      
      <ul class="tab-group">
        <li class="tab active"><a href="#signup">Sign Up</a></li>
        <li class="tab"><a href="#login">Log In</a></li>
      </ul>
      
      <div class="tab-content">
        <div id="signup">   

          <h1>Let's play.</h1>
        <?php
          echo "	<form action=".$_SERVER['PHP_SELF']." method='POST'>	";
        ?>
          <div class="top-row">
            <div class="field-wrap">
              <label>
                Choose login<span class="req">*</span>
              </label>
              <input type="text" name="login" required autocomplete="off" />
            </div>
        
            <div class="field-wrap">
	           	<label>
	              Password<span class="req">*</span>
	            </label>
	            <input type="password" name="password" required autocomplete="off" pattern=".{6,}" required title="6 characters minimum"/>
	        </div>

	        <div class="field-wrap">
	           	<label>
	              Verify password<span class="req">*</span>
	            </label>
	            <input type="password" name="passwordbis" required autocomplete="off"  pattern=".{6,}" required title="6 characters minimum"/>
	        </div>
          </div>
          
          <button type="submit" name="sign_up" value="Register" class="button button-block"/>Get Started</button>
          
          </form>

        </div>
        
        <div id="login">   
          <h1>Welcome Back!</h1>
        <?php
          echo "	<form action=".$_SERVER['PHP_SELF']." method='POST'>	";
        ?>
            <div class="field-wrap">
            <label>
              Login<span class="req">*</span>
            </label>
            <input type="text" name="login" required autocomplete="on"/>
          </div>
          
          <div class="field-wrap">
            <label>
              Password<span class="req">*</span>
            </label>
            <input type="password" name="password" required autocomplete="off"/>
          </div>
          
          <button type="submit" name="log" value="Connexion" class="button button-block"/>Log In</button>
          
          </form>

        </div>
        
      </div><!-- tab-content -->
      
	</div>
  <div class="stars"></div>
  <div class="twinkling"></div>

</body>
</html>