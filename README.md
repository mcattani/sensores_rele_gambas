# sensores_rele_gambas
Aplicación hecha en Gambas que recibe información de sensores conectados a un Arduino, también permite controlar la activación/desactivación de un relé.

Se trata de una aplicación que recibe información de sensores conectados a un *Arduino* (en este caso utilicé un *Arduino Nano*, pero se puede utilizar cualquiera). Los datos que recibe la aplicación son: temperatura, humedad (ambos recogidos a través de un sensor *DHT11*) y nivel de luz (recogido utilizando una *fotorresistencia* o *LDR*). También hay conectado al Arduino un *relé* que es controlado por la aplicación, el mismo enciende/apaga una lámpara, cuando es activado/desactivado.

El programa permite también la activación/desactivación automática del relé según la cantidad de luz que el usuario establezca como límite.

Para una descripción más completa sobre este proyecto visitá mi blog: https://thenerdyapprentice.blogspot.com/

Saludos!
