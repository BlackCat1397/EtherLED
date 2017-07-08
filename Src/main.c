/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "wizchip_conf.h"
#include "socket.h"
#include <string.h>

int i = _WIZCHIP_;
#define SEPARATOR            "=============================================\r\n"
#define WELCOME_MSG  		 "Welcome to STM32Nucleo Ethernet configuration\r\n"
#define NETWORK_MSG  		 "Network configuration:\r\n"
#define IP_MSG 		 		 "  IP ADDRESS:  %d.%d.%d.%d\r\n"
#define NETMASK_MSG	         "  NETMASK:     %d.%d.%d.%d\r\n"
#define GW_MSG 		 		 "  GATEWAY:     %d.%d.%d.%d\r\n"
#define MAC_MSG		 		 "  MAC ADDRESS: %x:%x:%x:%x:%x:%x\r\n"
//#define GREETING_MSG 		 "Well done guys! Welcome to the IoT world. Bye!\r\n"
#define GREETING_MSG 		 "<button type=\"button\">Click on Me!</button> <img src=\"http://a816.phobos.apple.com/us/r30/Purple2/v4/c7/09/1d/c7091d0b-a28b-6928-a5e0-6daa7c650f65/mzl.knuqwzfs.png\">"

char page[] = {"HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\"> <title>1 Выбор цвета</title> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <script type=\"text/javascript\" src=\"https://code.jquery.com/jquery-3.1.0.slim.min.js\"></script><style type=\"text/css\"></style> <link rel=\"stylesheet\" href=\"http://ajax.googleapis.com/ajax/libs/jqueryui/1.11.2/themes/smoothness/jquery-ui.css\"> <script src=\"https://code.jquery.com/ui/1.12.1/jquery-ui.min.js\"></script> <link rel=\"stylesheet\" href=\"css/style.css\"></link> <style>*{margin: 0; font: 12px Arial, sans-serif;}#inputColor{width: 100px;height: 50px;}/* colorpicker styles */.colorpicker{background-color: #222222; border-radius: 5px 5px 5px 5px; box-shadow: 2px 2px 2px #444444; color: #FFFFFF; font-size: 12px; width: 460px;margin: 0px auto;overflow: auto;}#picker{cursor: crosshair; float: left; margin: 10px 0 10px 10px; border: 0;}.controls{float: right; margin: 10px;}.controls > div{border: 1px solid #2F2F2F; margin-bottom: 5px; overflow: hidden; padding: 5px;}.controls label{float: left;}.controls > div input{background-color: #121212; border: 1px solid #2F2F2F; color: #DDDDDD; float: right; font-size: 13px; height: 14px; margin-left: 6px; text-align: center; text-transform: uppercase; width: 75px;}.myButton{color: #fff; width: 120px; margin: 10px 0 10px 0;border: solid 1px #999;"};
char page2[] = {"padding: 5px 0; border-radius: 3px; -moz-border-radius: 3px; -khtml-border-radius: 3px; -webkit-border-radius: 3px; background: -webkit-gradient(linear, left top, left bottom, from(#444444), to(#666666)); background: -moz-linear-gradient(top, #444444, #666666); background-image: -o-linear-gradient(top,rgb(68,68,68), rgb(102,102,102)); filter: progid:DXImageTransform.Microsoft.gradient(startColorstr='#444444', endColorstr='#666666');}.myButton:hover{font-weight: bold; background: -webkit-gradient(linear, left top, left bottom, from(#666666), to(#444444)); background: -moz-linear-gradient(top, #666666, #444444); background-image: -o-linear-gradient(top,rgb(102,102,102), rgb(68,68,68)); rgb(102,102,102) filter: progid:DXImageTransform.Microsoft.gradient(startColorstr='#666666', endColorstr='#444444'); box-shadow: 1px 1px 15px -2px rgba(255,255,255,0.75);}.active{font-weight: bold; background: -webkit-gradient(linear, left top, left bottom, from(#666666), to(#444444)); background: -moz-linear-gradient(top, #666666, #444444); background-image: -o-linear-gradient(top,rgb(102,102,102), rgb(68,68,68)); rgb(102,102,102) filter: progid:DXImageTransform.Microsoft.gradient(startColorstr='#666666', endColorstr='#444444'); box-shadow: 1px 1px 15px -2px rgba(255,255,255,0.75);}#RGB{margin-bottom: 45px;}.slaider{clear: both;padding: 10px;font-size: 13px;}.slaider input{margin: 10px 15px;width: 315px;}/*input[type=range]{-webkit-appearance: none;border-radius: 8px;"};
char page3[] = {"height: 7px;border: 1px solid #bdc3c7;background-color: #fff;}*/.out{position: relative;top: -7px;}.clear{clear: both;}@media only all and (max-width: 471px){.colorpicker{width: 320px;}.controls{float: left;}.controls > div{float: left;margin-right: 17px;}.controls > div:nth-child(3){margin-right: 0px;}.controls > div input{width: 60px;}#RGB{margin: 10px auto;float: none;width: 100px;}#function{float: right;}.slaider input{margin: 10px;width: 185px;}}</style></head> <body><div class=\"colorpicker\"><canvas id=\"picker\" var=\"1\" width=\"300\" height=\"300\"></canvas><div class=\"controls\"><div><label>R</label> <input type=\"text\" id=\"rVal\"></div><div><label>G</label> <input type=\"text\" id=\"gVal\"></div><div><label>B</label> <input type=\"text\" id=\"bVal\"></div><div id=\"RGB\"><label>RGB</label> <input type=\"text\" id=\"rgbVal\"></div><p id=\"function\"><button onclick='function1()' class=\"myButton\">Кнопка</button></p><p><button onclick='switchOf()' class=\"myButton\" id=\"switch\">switch off</button></p></div><div class=\"slaider\"><form class=\"range-examples\"><label for=\"param1\" class=\"out\">Параметр 1</label><input type=\"range\" min=\"0\" max=\"250\" value=\"50\" id=\"param1\" step=\"1\" oninput=\"outputUpdate(value)\"><output for=\"param1\" id=\"vol\" class=\"out\">50</output><div class=\"clear\"></div><label for=\"param2\" class=\"out\">Параметр 2</label><input type=\"range\" min=\"0\" max=\"250\" value=\"70\" id=\"param2\""};
char page4[] = {"step=\"1\" oninput=\"outputUpdate2(value)\"><output for=\"param2\" id=\"vol2\" class=\"out\">70</output></form><script>function outputUpdate(vol){document.querySelector('#vol').value=vol;}function outputUpdate2(vol){document.querySelector('#vol2').value=vol;}$(function(){$('#switch').on('click', function(){console.log( $(this).text() );$(this).toggleClass('active'); var q=$(this).text();(q=='switch off') ? ($(this).text('switch on') ) : ($(this).text('switch off'));});});</script></div></div><script>var red=0; var green=0; var blue=0; var brColor=255; var brWhite=255; function GetArduinoIO(){nocache=\"&nocache=\" + Math.random() * 1000000;var request=new XMLHttpRequest();request.onreadystatechange=function(){if (this.readyState==4){if (this.status==200){if (this.responseXML !=null){/* XML file received - contains LED brightness and colour */var count;/* LED 1 */if (this.responseXML.getElementsByTagName('LED')[0].childNodes[0].nodeValue===\"checked\"){document.LED_form.LED1.checked=true;}else{document.LED_form.LED1.checked=false;}/* LED 2 */if (this.responseXML.getElementsByTagName('LED')[1].childNodes[0].nodeValue===\"checked\"){document.LED_form.LED2.checked=true;}else{document.LED_form.LED2.checked=false;}}}}}/* send HTTP GET request with LEDs to switch on/off if any*//*request.open(\"GET\", \"ajax_inputs\" + red + green + blue + brColor + brWhite + nocache, true);*/ request.open(\"SET\", \"dig_outputs_\" + \"r\" + red +\"g\" + green + \"b\" + blue + \"brC\""};
char page5[] = {"+ brColor + \"brW\" + brWhite + nocache, true); request.send(null); console.log(\"!\"); /*setTimeout('GetArduinoIO()', 1000);*/}$(function(){var bCanPreview=true; /* can preview */ /* create canvas and context objects */ var canvas=document.getElementById('picker'); var ctx=canvas.getContext('2d'); /* drawing active image */ var image=new Image(); image.onload=function (){ctx.drawImage(image, 0, 0, image.width, image.height); /* draw the image on the canvas */}$('#picker').mousemove(function(e){/* mouse move handler */ if (bCanPreview){/* get coordinates of current position */ var canvasOffset=$(canvas).offset(); var canvasX=Math.floor(e.pageX - canvasOffset.left); var canvasY=Math.floor(e.pageY - canvasOffset.top); /* get current pixel */ var imageData=ctx.getImageData(canvasX, canvasY, 1, 1); var pixel=imageData.data; /* update preview color */ var pixelColor=\"rgb(\"+pixel[0]+\", \"+pixel[1]+\", \"+pixel[2]+\")\"; $('.preview').css('backgroundColor', pixelColor); /* update controls */ $('#rVal').val(pixel[0]); $('#gVal').val(pixel[1]); $('#bVal').val(pixel[2]); if(red !=pixel[0] || green !=pixel[1] || blue !=pixel[2]){red=pixel[0]; green=pixel[1]; blue=pixel[2];if(f)GetArduinoIO();}console.log(pixel[0]); $('#rgbVal').val(pixel[0]+','+pixel[1]+','+pixel[2]); var dColor=pixel[2] + 256 * pixel[1] + 65536 * pixel[0]; $('#hexVal').val('#' + ('0000' + dColor.toString(16)).substr(-6));}});image.crossOrigin=\"anonymous\";image.src=\"https://dl.dropboxusercontent.com/s/rm54qmnq9zaxgq4/colorwheel5.png?dl=0\";"};
char page6[] = {"$('#picker').click(function(e){/* click event handler */ bCanPreview=!bCanPreview;}); $('.preview').click(function(e){/* preview click */ $('.colorpicker').fadeToggle(\"slow\", \"linear\"); bCanPreview=true;});});</script> </body></html>"};

#define CONN_ESTABLISHED_MSG "Connection established with remote IP: %d.%d.%d.%d:%d\r\n"
#define SENT_MESSAGE_MSG	 "Sent a message. Let's close the socket!\r\n"
#define WRONG_RETVAL_MSG	 "Something went wrong; return value: %d\r\n"
#define WRONG_STATUS_MSG	 "Something went wrong; STATUS: %d\r\n"
#define LISTEN_ERR_MSG		 "LISTEN Error!\r\n"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
char msg[60];
int tColor[4], tSwitch[2];

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
void cs_sel() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET); //CS LOW
}

void cs_desel() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET); //CS HIGH
}

uint8_t spi_rb(void) {
	uint8_t rbuf;
	HAL_SPI_Receive(&hspi2, &rbuf, 1, 0xFFFFFFFF);
	return rbuf;
}

void spi_wb(uint8_t b) {
	HAL_SPI_Transmit(&hspi2, &b, 1, 0xFFFFFFFF);
}
/* USER CODE END 0 */

void set_color(short channel, int red, int green, int blue, int white) {
	//TODO!! FIX GAMMA

  int gamma[] = {0, 1, 2, 4, 7, 11, 17, 24,
                 32, 42, 53, 65, 79, 94, 111, 129,
                 148, 169, 192, 216, 242, 270, 299, 330,
                 362, 396, 432, 469, 508, 549, 591, 635,
            /*4*/681, 729, 779, 830, 883, 938, 995, 1053,
				 1113, 1175, 1239, 1305, 1373, 1443, 1514, 1587,
				 1663, 1740, 1819, 1900, 1983, 2068, 2155, 2243,
				 2334, 2427, 2521, 2618, 2717, 2817, 2920, 3024,
			/*8*/3131, 3240, 3350, 3463, 3578, 3694, 3813, 3934,
				 4057, 4182, 4309, 4438, 4570, 4703, 4838, 4976, // replace gamma!
			     5115, 5257, 5401, 5547, 5695, 5845, 5998, 6152,
				 6309, 6468, 6629, 6792, 6957, 7124, 7294, 7466,
		   /*12*/7640, 7816, 7994, 8175, 8358, 8543, 8730, 8919,
		         9111, 9305, 9501, 9699, 9900, 10102, 10307, 10515,
				 10724, 10936, 11150, 11366, 11585, 11806, 12029, 12254,
				 12482, 12712, 12944, 13179, 13416, 13655, 13896, 14140,
		   /*16*/14386, 14635, 14885, 15138, 15394, 15652, 15912, 16174,
				 16439, 16706, 16975, 17247, 17521, 17798, 18077, 18358,
				 18642, 18928, 19216, 19507, 19800, 20095, 20393, 20694,
				 20996, 21301, 21609, 21919, 22231, 22546, 22863, 23182,
				 23504, 23829, 24156, 24485, 24817, 25151, 25487, 25826,
				 26168, 26512, 26858, 27207, 27558, 27912, 28268, 28627,
				 28988, 29351, 29717, 30086, 30457, 30830, 31206, 31585,
				 31966, 32349, 32735, 33124, 33514, 33908, 34304, 34702,
				 35103, 35507, 35913, 36321, 36732, 37146, 37562, 37981,
				 38402, 38825, 39252, 39680, 40112, 40546, 40982, 41421,
		 		 41862, 42306, 42753, 43202, 43654, 44108, 44565, 45025,
	 			 45487, 45951, 46418, 46888, 47360, 47835, 48313, 48793,
				 49275, 49761, 50249, 50739, 51232, 51728, 52226, 52727,
				 53230, 53736, 54245, 54756, 55270, 55787, 56306, 56828,
				 57352, 57879, 58409, 58941, 59476, 60014, 60554, 61097,
				 61642, 62190, 62741, 63295, 63851, 64410, 64971, 65535};


  if(red + green + blue > 0) {
	  tColor[2] = (gamma[blue>255?255:blue]+1)/64; //D8 - blue
	  tColor[0] = (gamma[red>255?255:red]+1)/64; //D2 - red
	  tColor[1] = (gamma[green>255?255:green]+1)/64; //D3 - green
  }
  if(white > 0)
	  tColor[3] = (gamma[white>255?255:white]+1)/64; //D7 - white


	//TIM1: PA8_, PA9_, PA10_, PA11
	//TIM2: PA15, PB3_
	//TIM3: PA6_, PA7_, PB0, PB1
	//TIM4: PB6!, PB7, PB8_, PB9_
	//TIM5: PA0, PA1

	//PA0, PA1, PA6, PA7, PA11, PA15, PB0, PB1, PB6, PB7, PB8, PB9

	//channel 0: PA8, PA9, PA10, PB3
	//channel 1: PA6, PA7, PB8, PB9

  switch(channel){
    case 0:
	  TIM1->CCR1 = (gamma[white>255?255:white]+1)/64; //D7 - white
	  TIM1->CCR2 = (gamma[blue>255?255:blue]+1)/64; //D8 - blue
	  TIM1->CCR3 = (gamma[red>255?255:red]+1)/64; //D2 - red
	  TIM2->CCR2 = (gamma[green>255?255:green]+1)/64; //D3 - green
	  break;
    case 1:
  	  TIM4->CCR4 = (gamma[blue>255?255:blue]+1)/64; //D10 - red
	  TIM3->CCR2 = (gamma[white>255?255:white]+1)/64; //D11 - green
	  TIM3->CCR1 = (gamma[green>255?255:green]+1)/64; //D12 - blue
	  TIM4->CCR3 = (gamma[red>255?255:red]+1)/64; //D14 - white
	  break;
  }
}

void checkSwitch() {
	int t[2] = {1, 1};
	int tt[2] = {1, 1};

	if (GPIOC->IDR & 1)
		t[0] = 0;
	if (GPIOC->IDR & 2)
		t[1] = 0;

	int k1 = 0, k2 = 0;
	for(int i = 0; i < 100; i++) {
		if (GPIOC->IDR & 1)
			tt[0] = 0;
		if (GPIOC->IDR & 2)
			tt[1] = 0;

		if(tSwitch[0] != tt[0])
			k1++;
		if(tSwitch[1] != tt[1])
			k2++;
	}
	if(k1 > 99) {
		tSwitch[0] = tSwitch[0]?0:1;
		if(TIM1->CCR1)
			TIM1->CCR1 = 0;
		else
			TIM1->CCR1 = tColor[3];
	}

	if(k2 > 99) {
		tSwitch[1] = tSwitch[1]?0:1;
		if(TIM1->CCR2 || TIM1->CCR3 || TIM2->CCR2) {
			TIM1->CCR2 = 0;
			TIM1->CCR3 = 0;
			TIM2->CCR2 = 0;
		}
		else {
			TIM1->CCR2 = tColor[2];
			TIM1->CCR3 = tColor[0];
			TIM2->CCR2 = tColor[1];
		}
	}
}

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI2_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();

  /* USER CODE BEGIN 2 */
  uint8_t retVal, sockStatus;
  int16_t rcvLen;
  uint8_t rcvBuf[20], bufSize[] = {2, 2, 2, 2};

  reg_wizchip_cs_cbfunc(cs_sel, cs_desel);
  reg_wizchip_spi_cbfunc(spi_rb, spi_wb);

  wizchip_init(bufSize, bufSize);
  wiz_NetInfo netInfo = { .mac 	= {0x00, 0x08, 0xdc, 0xab, 0xcd, 0x13},	// Mac address
                          .ip 	= {192, 168, 59, 137},					// IP address
                          .sn 	= {255, 255, 255, 0},					// Subnet mask
                          .gw 	= {192, 168, 59, 30}};					// Gateway address
  wizchip_setnetinfo(&netInfo);
  wizchip_getnetinfo(&netInfo);



  char buffer[256];

  HAL_TIM_PWM_Start(&htim1, 1);
  HAL_TIM_PWM_Start(&htim1, 2);
  HAL_TIM_PWM_Start(&htim1, 3);
  HAL_TIM_PWM_Start(&htim2, 1);
  HAL_TIM_PWM_Start(&htim3, 1);
  HAL_TIM_PWM_Start(&htim3, 2);
  HAL_TIM_PWM_Start(&htim4, 3);
  HAL_TIM_PWM_Start(&htim4, 4);

  TIM1->CCER = 0x1111;
  TIM1->ARR = 1024;
  TIM2->CCER = 0x1111;
  TIM2->ARR = 1024;
  TIM3->CCER = 0x1111;
  TIM3->ARR = 1024;
  TIM4->CCER = 0x1111;
  TIM4->ARR = 1024;


  checkSwitch();
  int del = 500;
  for(int i = 0; i < 4; i++)
	  set_color(i, 255, 0, 0, 0);
  HAL_Delay(del);
  for(int i = 0; i < 4; i++)
	  set_color(i, 0, 255, 0, 0);
  HAL_Delay(del);
  for(int i = 0; i < 4; i++)
	  set_color(i, 0, 0, 255, 0);
  HAL_Delay(del);
  for(int i = 0; i < 4; i++)
	  set_color(i, 0, 0, 0, 255);
  HAL_Delay(del);
  for(int i = 0; i < 4; i++)
  	  set_color(i, 0, 0, 0, 0);



  while(1) {
    socket(0, Sn_MR_TCP, 80, 0);
	if(listen(0) == SOCK_OK) {
	  while(getSn_SR(0) == SOCK_LISTEN) {
  	    HAL_Delay(100);
  	    checkSwitch();
	  }
	  if(getSn_SR(0) == SOCK_ESTABLISHED) {
		uint8_t remoteIP[4];
		uint16_t remotePort;
		/* Retrieving remote peer IP and port number */
		getsockopt(0, SO_DESTIP, remoteIP);
		getsockopt(0, SO_DESTPORT, (uint8_t*)&remotePort);
		while(getSn_SR(0) == SOCK_ESTABLISHED) {
		  int n = recv(0, buffer, 250);

		  int i = 0;
		  while(i < n){
			short chan = 0;
			int r = 0, g = 0, b = 0, w = 0;

			while((buffer[i]>'9'||buffer[i]<'0') && i<n) //skip until number
		      i++;

			chan = buffer[i]-48;


			while((buffer[i+1]>'9'||buffer[i+1]<'0') && i<n) //skip until number
		      i++;
		    i++;


		    while((buffer[i]<='9'&&buffer[i]>='0')&&i<n){//get red
			  r *= 10;
		      r += buffer[i]-48;
		      i++;
		    }
			while((buffer[i+1]>'9'||buffer[i+1]<'0') && i<n) //skip until number
			  i++;
			i++;


			while((buffer[i]<='9'&&buffer[i]>='0')&&i<n){//get green
			  g *= 10;
			  g += buffer[i]-48;
			  i++;
			}
			while((buffer[i+1]>'9'||buffer[i+1]<'0') && i<n) //skip until number
			  i++;
			i++;


			while((buffer[i]<='9'&&buffer[i]>='0')&&i<n){//get blue
			  b *= 10;
			  b += buffer[i]-48;
			  i++;
			}
			while((buffer[i+1]>'9'||buffer[i+1]<'0') && i<n) //skip until number
			  i++;
			i++;


			while((buffer[i]<='9'&&buffer[i]>='0')&&i<n){//get white
			  w *= 10;
			  w += buffer[i]-48;
			  i++;
			}
			//TIM1->CCER &= 0xEEEE;
			//TIM2->CCER &= 0xEEEE;
			set_color(chan, r, g, b, w);
			//TIM1->CCER = 0x1111;
			//TIM2->CCER = 0x1111;
		  }

		  send(0, buffer, n);
		}
	  }
	}
	close(0);
  }
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
