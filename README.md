# ESP32-bot
El programa se encarga de enviar un mensaje a un bot de Whatsapp y otro a un bot de Telegram

Mensajería por Whatsapp:
https://www.callmebot.com/blog/whatsapp-messages-from-esp8266-esp32/#google_vignette

Mensajería por Telegram:
https://www.callmebot.com/blog/telegram-text-messages/

En resumen: 
Para usar bot de Whatsapp  
Agregar el número +34 644 95 42 75 a los contactos  
Enviar el mensaje "I allow callmebot to send me messages" al contacto recientemente agregado  
Esperar a recibir la apiKey. Llegará el mensaje “API Activated for your phone number. Your APIKEY is 123123”



Para usar bot de Telegram
Desde un browser o desde la ESP32 se puede enviar un mensaje al usuario que desee.
El usuario es el campo Username que puede cambiarse desde Telegram→Settings→Account. 


Importante: Necesitás autorizar a CallMeBot desde el siguiente link
Enviar el siguiente mensaje de Telegram para probarlo
https://api.callmebot.com/text.php?user=@myusername&text=This+is+a+test+from+CallMeBot
Nota: cambiar por el usuario autorizado y el texto deseado

Enviar el siguiente mensaje de Whatsapp para probarlo
https://api.callmebot.com/whatsapp.php?phone=[phone_number]&text=[message]&apikey=[your_apikey]
Nota: cambiar por nuestro número de teléfono, el texto deseado y la ApiKey que nos devolvió el bot
