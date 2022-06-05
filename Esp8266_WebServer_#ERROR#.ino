  #include <ESP8266WiFi.h> //Biblioteca para funcionamento do WiFi do ESP
  #include <ESP8266WebServer.h> //Biblioteca para o ESP funcionar como servidor

  const char* ssid = "Bruna";  // Rede WiFi
  const char* password = "gabriel14179";  //Senha da Rede WiFi


  ESP8266WebServer server(80); //server na porta 80

  float temperatura; //variável para armazenar a temperatura
  float umidade; //Variável para armazenar a umidade

  void setup() {
    Serial.begin(9600); //Inicializa a comunicação serial
    delay(50); // ?Intervalo para aguardar a estabilização do sistema

    Serial.println("Conectando a Rede: "); //Imprime na serial a mensagem
    Serial.println(ssid); //Imprime na serial o nome da Rede Wi-Fi

    WiFi.begin(ssid, password); //Inicialização da comunicação Wi-Fi

    //Verificação da conexão
    while (WiFi.status() != WL_CONNECTED) { //Enquanto estiver aguardando status da conexão
      delay(1000);
      Serial.print("."); //Imprime pontos
    }
    Serial.println("");
    Serial.println("WiFi Conectado");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP()); //Função para exibir o IP da ESP

    server.on("/", handle_OnConnect); //Servidor recebe uma solicitação HTTP - chama a função handle_OnConnect
    server.onNotFound(handle_NotFound); //Servidor recebe uma solicitação HTTP não especificada - chama a função handle_NotFound

    server.begin(); //Inicializa o servidor
    Serial.println("Servidor HTTP inicializado");

  }

  void loop() {
    server.handleClient(); //Chama o método handleClient()
  }

  void handle_OnConnect() {
    Serial.print("Temperatura: ");
    Serial.print(""); //Imprime no monitor serial o valor da temperatura lida
    Serial.println(" ºC");
    Serial.print("Umidade: ");
    Serial.print(""); //Imprime no monitor serial o valor da umidade lida
    Serial.println(" %");
    server.send(200, "text/html", EnvioHTML(1, 2)); //Envia as informações usando o código 200, especifica o conteúdo como "text/html" e chama a função EnvioHTML

  }

  void handle_NotFound() { //Função para lidar com o erro 404
    server.send(404, "text/plain", "Não encontrado"); //Envia o código 404, especifica o conteúdo como "text/pain" e envia a mensagem "Não encontrado"

  }

  String EnvioHTML(float Temperaturastat, float Umidadestat) { //Exibindo a página da web em HTML
    String ptr = ""; //Indica o envio do código HTML
    ptr += "<!DOCTYPE html>";
    ptr += "<html lang=\"pt-BR\">";
    ptr += "<head>";
    ptr += "    <meta charset=\"UTF-8\">";
    ptr += "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">";
    ptr += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
    ptr += "    <title>SmartPlant<\/title>";
    ptr += "    <link rel=\"shortcut icon\" href=\"https:\/\/www.santos.sp.gov.br\/static\/files_www\/hotsite\/compostasantos\/bem-estar.png\" type=\"image\/x-icon\">";
    ptr += "    <style>";
    ptr += "      div#visible {";
    ptr += "          display: none;";
    ptr += "      }";
    ptr += "      body {";
    ptr += "          background-color: rgb(198, 248, 198);";
    ptr += "          text-align: center;";
    ptr += "      }";
    ptr += "      meter {";
    ptr += "          width: 200px;";
    ptr += "          height: 25px;";
    ptr += "      }";
    ptr += "      img#perfil {";
    ptr += "          border-radius: 50%;";
    ptr += "          width: 180px;";
    ptr += "          height: 180px;";
    ptr += "      }";
    ptr += "      img#pumpIcon {";
    ptr += "          margin-top: 20px;";
    ptr += "          width: 40px;";
    ptr += "          height: 40px;";
    ptr += "      }";
    ptr += "      #container {";
    ptr += "          border-radius: 10px; ";
    ptr += "      }";
    ptr += "      #visible {";
    ptr += "          margin-top: 150px;";
    ptr += "      }";
    ptr += "      p {";
    ptr += "          margin: 0px;";
    ptr += "      }";
    ptr += "      ";
    ptr += "    .switch {";
    ptr += "    position: relative;";
    ptr += "    display: inline-block;";
    ptr += "    width: 60px;";
    ptr += "    height: 34px;";
    ptr += "    }";
    ptr += "    .switch input { ";
    ptr += "    opacity: 0;";
    ptr += "    width: 0;";
    ptr += "    height: 0;";
    ptr += "    }";
    ptr += "    .slider {";
    ptr += "    position: absolute;";
    ptr += "    cursor: pointer;";
    ptr += "    top: 0;";
    ptr += "    left: 0;";
    ptr += "    right: 0;";
    ptr += "    bottom: 0;";
    ptr += "    background-color: #ccc;";
    ptr += "    -webkit-transition: .4s;";
    ptr += "    transition: .4s;";
    ptr += "    }";
    ptr += "    .slider:before {";
    ptr += "    position: absolute;";
    ptr += "    content: \"\";";
    ptr += "    height: 26px;";
    ptr += "    width: 26px;";
    ptr += "    left: 4px;";
    ptr += "    bottom: 4px;";
    ptr += "    background-color: white;";
    ptr += "    -webkit-transition: .4s;";
    ptr += "    transition: .4s;";
    ptr += "    }";
    ptr += "    input:checked + .slider {";
    ptr += "    background-color: green;";
    ptr += "    }";
    ptr += "    input:focus + .slider {";
    ptr += "    box-shadow: 0 0 1px green;";
    ptr += "    }";
    ptr += "    input:checked + .slider:before {";
    ptr += "    -webkit-transform: translateX(26px);";
    ptr += "    -ms-transform: translateX(26px);";
    ptr += "    transform: translateX(26px);";
    ptr += "    }";
    ptr += "    .slider.round {";
    ptr += "    border-radius: 34px;";
    ptr += "    }";
    ptr += "    .slider.round:before {";
    ptr += "    border-radius: 50%;";
    ptr += "    }";
    ptr += "    <\/style>";
    ptr += "    <script>";
    ptr += "        let user = prompt(\"Usuário: \");";
    ptr += "        let password = prompt(\"Senha:\");";
    ptr += "        let delay = 0";
    ptr += "  ";
    ptr += "        function bar(progresso) {";
    ptr += "            document.querySelector(\"#container\").innerHTML = `<meter value='${progresso}' max='100'>${progresso}%<\/meter>`";
    ptr += "            document.querySelector(\"#porcentagem\").innerHTML = `<p><b>${progresso}%<\/b><\/p>`";
    ptr += "        }";
    ptr += "    <\/script>";
    ptr += "<\/head>";
    ptr += "<body>";
    ptr += "    <div id=\"visible\">";
    ptr += "        <img id=\"perfil\" src=\"https:\/\/imgkub.com\/images\/2022\/05\/21\/bb4d14fa-6cc7-4345-8e5b-b7ae8432aea2.jpg\" alt=\"Imagem de uma plantinha aleatória da internet\" border=\"0\">";
    ptr += "        <div>";
    ptr += "            <p><b>Umidade do solo<\/b><\/p>";
    ptr += "            <div id=\"container\"><\/div>";
    ptr += "            <div id=\"porcentagem\"><\/div>";
    ptr += "        <\/div>";
    ptr += "        <img id=\"pumpIcon\" src=\"https:\/\/imgkub.com\/images\/2022\/05\/21\/pump.png\" alt=\"pump.png\" border=\"0\">";
    ptr += "        <div id=\"button\">";
    ptr += "            <label class=\"switch\">";
    ptr += "                <input type=\"checkbox\">";
    ptr += "                <span class=\"slider round\"><\/span>";
    ptr += "            <\/label>";
    ptr += "        <\/div>";
    ptr += "        ";
    ptr += "    <\/div>";
    ptr += "    <script type=\"text\/javascript\">";
    ptr += "        if(user == \"teste\" && password == \"teste\") {";
    ptr += "            document.getElementById('visible').style.display = 'block';";
    ptr += "        } else {";
    ptr += "            setTimeout(function(){document.location.reload(true);},delay);";
    ptr += "        }";
    ptr += "        bar(56)";
    ptr += "    <\/script>";
    ptr += "<\/body>";
    ptr += "<\/html>";

    return ptr;

  }
