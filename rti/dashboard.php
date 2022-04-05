
<?php

/*
session_start();
if ( !isset($_SESSION['username'])){
  header("refresh:5;url=index.php");
  die("Acesso restrito.");
  
}*/


$valor_temperatura = file_get_contents("api/files/temperatura/valor.txt");
$valor_hora = file_get_contents("api/files/temperatura/hora.txt");
$valor_nome = file_get_contents("api/files/temperatura/nome.txt")
?>



<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="refresh" content="5">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">

    <title>Plataforma IoT</title>
  </head>
  <body>

    <nav class="navbar navbar-light bg-light">
        <div class="container-fluid">
          <a class="navbar-brand">Plataforma IoT</a>
          <form class="d-flex">
       
            <button class="btn btn-outline-success" type="submit">Logout</button>
          </form>
        </div>
      </nav><br><br>

    <div class="container">
        <div class="card">
            <div class="card-body">
                <img src="img/estg.png" width="300px" class="float-end" alt="Logotipo do IPleiria">
                <h1>Servidor IoT</h1>
                <p>Bem Vindo <p>UTILIZADOR QUIM BARREIROS</p></p>
                <small>Redes e Tecnologias de internet - Tecnologias Informáticas</small>
            </div>
        </div>
    </div>

    <br>

    <div class="container">
        <div class="row">

            <div class="col-sm-4 text-center">
                <div class="card">
                    <div class="card-header"> <b>Luminosidade: </b>80%</div>
                    <div class="card-body"> <img src="img/dia.png" alt=""></div>
                    <div class="card-footer"><b>Atualização: </b> 2022/03/01 14:31 - <a href="">Hitórico</a> </div>
                  </div>
            </div>

            <div class="col-sm-4 text-center">
                <div class="card">
                    <div class="card-header"><b><?php echo($valor_nome) ?></b> <?php echo($valor_temperatura)?></div>
                    <div class="card-body"> <img src="img/temperature.png" alt=""></div>
                    <div class="card-footer"><b>Atualização: </b> <?php echo($valor_hora) ?> - <a href="">Hitórico</a> </div>
                  </div>
            </div>

            <div class="col-sm-4 text-center">
                <div class="card">
                    <div class="card-header"><b>Porta:</b> Fechada</div>
                    <div class="card-body"> <img src="img/door.png" alt=""></div>
                    <div class="card-footer"><b>Atualização: </b> 2022/03/01 14:31 - <a href="">Hitórico</a> </div>
                  </div>
            </div>

        </div><br>

        <div class="card">
  <div class="card-header">Tabela de Sensores</div>
  <div class="card-body">
  <table class="table">
  <thead>
    <tr>
      <th scope="col">Tipo de Dispositivo</th>
      <th scope="col">Valor</th>
      <th scope="col">Data de Atua.</th>
      <th scope="col">Estado Alertas</th>
    </tr>
  </thead>
  <tbody>

    <tr>
      <th scope="row">Sensor de luz</th>
      <td>Mark</td>
      <td>Otto</td>
      <td>@mdo</td>
    </tr>

    <tr>
      <th scope="row"><?php echo($valor_nome) ?></th>
      <td><?php echo($valor_temperatura) ?></td>
      <td><?php echo($valor_hora) ?> </td>
      <td>OK</td>
    </tr>

    <tr>
      <th scope="row">Humidade</th>
      <td colspan="2">Larry the Bird</td>
      <td>@twitter</td>
    </tr>

    <tr>
      <th scope="row">Luminosidade</th>
      <td colspan="2">Larry the Bird</td>
      <td>@twitter</td>
    </tr>

  </tbody>
</table>


 
 </div>
</div>
    
  </body>
</html>