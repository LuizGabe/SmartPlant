# SmartPlant
<h>Em minha casa eu tenho uma horta que quero automatizar, a fim de não morrer mais plantas... Brincadeiras a parte este que mesmo tendo um objetivo interessante, ele servirá para desenvolver minhas habilidades com solda, IOT e desenvolvimento web.
  Sabendo disso, abaixo terão alguns tópicos que este projeto irá seguir:
  <li><a href="#por-que-uma-smartplant">Por que uma SmartPlant?</a></li>
  <li><a href="#de-que-modo-este-projeto-se-desenvolverá">De que modo este projeto se desenvolverá?</a></li>
  <li><a href="#materiais">Materiais</a></li>
  <li><a href="#web-server---site-local">Web Server - Site Local</a></li>
  <li><a href="#código-esp8266">Código ESP8266</a></li>
  <li><a href="#esquema-elétrico">Esquema Elétrico</a></li>
  
<h2>Por que uma SmartPlant?</h2>
  <h>Eu escolhi uma SmartPlant pois eu vi em diversos canais no Youtube que este projeto é interessante para desenvolver minhas habilidades, de modo que posso aprender muito fazendo, e em segundo lugar é que eu estava com a necessidade de uma, para não precisar mais regar e além de que eu nem sempre sei de quanta água a planta está precisando.</h>
<h2>De que modo este projeto se desenvolverá?</h2>
  <h>Eu peguei um projeto de sensor de temperatura e umidade com web server, tirei o web server que estava no código e coloquei um que eu criei, mais bonito e mais funcional (bom, até agora não está tem funcional...) de modo que eu consiga ver a umidade em tempo real (será atualizado de 60 em 60 segundos, mas mesmo assim é em tempo real) e ainda acionar a bomba de água caso necessário (ele terá acionamento automático) assim não precisarei mais me preocupar se as prantas irão morrer.</h>
<h2>Materiais</h2>
  <li>Placa de Prototipagem ESP8266</li>
  <li>Módulo sensor de Umidade de Solo</li>
  <li>Módulo relé de um canal</li>
  <li>Bomba de água</li>
  <li>Fios para a ligação dos componentes</li>
  <li>Fonte de energia</li>
  
 
  
  <h5>Placa de Prototipagem ESP8266</h5>
  <h6>Para este projeto, eu utilizei a placa de desenvolvimento ESP8266, pois ela tem conexão com wifi e uma entrada analógica para o sensor e diversas portas digitais para o módulo relé, e para mais alguns componentes se você quiser adicionar.</h6>
  
  <h5>Módulo sensor de Umidade de Solo</h5>
  <h6>Este módulo foi usado por seu funcionamento ser simples, com uma porta analógica para saída mais precisa, e uma porta digital para uma saída menos precisa, de modo que podemos saber exatamente quanto de água tem no solo, ou se o solo está ou não umido. Este módulo é constituido de duas plaquinhas, uma será enterrada quase por inteiro e dela sairá dois fios, que conectará em um conversor de resistência para nível lógico, ou seja, o solo umido oferece uma resistencia e o conversor faz o ESP8266 entender essa resistência.</h6>
  
  <h5>Módulo relé de um canal</h5>
  <h6>Este módulo foi usado para que o ESP8266 consiga ligar ou desligar a bomba de água, pois a placa de prototipagem não consegue fornecer uma tensão e corrente para a bomba de água, assim o relé servirá como um interruptor que vai ligar a bomba com uma fonte de energia mais forte do que o ESP8266 consegue liberar, de modo que assim o ESP8266 consegue regar as plantas.</h6>
  
  <h5>Bomba de água</h5>
  <h6>A bomba de água será a responsável por puxar a água de um balde e regar as plantas, esta bomba de água pode ser substituida por uma válvula solenóid, porém não consegui encontrar uma com uma tensão e corrente baixa para o projeto.</h6>
  
  <h5>Fios para a ligação dos componentes</h5>
  <h6>Para a prototipagem foi usado fios do tipo "Jumper" e para o projeto final, foi usado fios de cabo de rede, são cabos simples e rígidos que são otimos bons para projetos assim.</h6>
  
  <h5>Fonte de energia</h5>
  <h6>Para a prototipagem foi usado um PowerBank (Carregador Portátil) e a energia da saída do computador, de modo que o desenvolvimento seja mais rápido. </h6>
  
   <h3>Materiais Opcionais</h3>
    <li>Caixa de Proteção</li>
    <li>Fonte de energia mais otimizada para o proposito do projeto</li>
  (no meu caso vou colocar um PowerBank, futuramente vou colocar uma pequena célula fotovoltaica)
  
  <h5>Caixa de Proteção</h5>
  <h6>Para este projeto que ficara fora de casa, decidi colocar dentro de uma case (caixa de proteção) que irá proteger os circuitos, neste projeto vou utilizar a estrutura de um roteador velho que tenho aqui em casa.</h6>
  
  <h5>Fonte de energia</h5>
  <h6>Para este projeto decidi utilizar um power bank (carregador portátil) enquanto desenvolvia o protótipo, para a semi-finalização usei uma fonte de celular, e para a finalização do projeto vou utilizar uma célula fotovoltaica de 12 volts e 2 wats, que será transformada em 5 volts e 4,8 wats, para carregar o banco de baterias do projeto, e a saída desse banco de baterias será de 5 volts, que entrará no relé e também se transformará em 3,3 volts e 7.27 wats e entrara no Sensor de umidade de solo e no ESP8266.</h6>
   
<h2>Web Server - Site Local</h2>
<h5>Esta página será acessada com um ip interno e uma porta que está no código (Aqui em minha casa ficor <b>192.168.1.109:553</b>)<h5>
<img src="https://imgkub.com/images/2022/06/06/imagem_2022-06-05_150740366.png" alt="Foto para visualizar como ficou a versão final do Web Server" border="0">
<h2>Código ESP8266</h2>
<h2>Esquema Elétrico</h2>
