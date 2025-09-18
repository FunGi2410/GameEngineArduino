
const char* uploadForm = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
  </head>
  <body>
    <style>
      .box {
        display: inline-block;  
        width: 720px;
        height: 200px;
        margin: 10px;
        background: lightblue;
        text-align: center;
        line-height: 50px;
        font-weight: bold;
      }
    </style>

    <div class="box">
      <h1>FunGi OTA</h1>
      <form method='POST' action='/update' enctype='multipart/form-data'>
        <input type='file' name='update'>
        <input type='submit' value='Nạp code vào!'>
      </form>
    </div>

    <div class="box">
      <h1>Serial Web</h1>
        <input type='text' value='Write'>
      </form>
    </div>

  </body>
</html>
)rawliteral";