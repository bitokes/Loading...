

<!--
<?php
$username="eu";
$password="lili";
if(isset($_POST['username'])){
    echo"O username submetido foi:".$_POST['username']."<br>";
}

if (isset($_POST['password'])){
    echo"A password submetida foi:".$_POST['password']."<br>";
}
    ?>


<?php

$username="eu";
$password="lili";


if($_POST['username'] == $username && $_POST['password'] == $password){
    header ("location: dashboard.php");
}else{
    echo"Não ok";
}
?>


<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <link rel="stylesheet" href="css/style.css">
    <title>PhP</title>

  </head>
  <body>
  
    <div class="container">

        <form method="post">

        <a href="index.php">
            <img src="imagens/estg.png" alt="">
        </a>
        

         <div class="mb-3">
            <label for="exampleInputEmail1" class="form-label">Utilizador</label>
            <input type="username" name="username" required placeholder="Utilizador" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp">
        </div>
        <div class="mb-3">
            <label for="exampleInputPassword1" class="form-label">Password</label>
            <input type="password" name="password" required placeholder="Password" class="form-control" id="exampleInputPassword1">
        </div>
    
        <button type="submit" class="btn btn-primary">Login</button>
        </form>

    </div>

  
 


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
  </body>
</html>