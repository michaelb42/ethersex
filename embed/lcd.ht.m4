changequote({{,}})dnl
ifdef({{conf_LCD}}, {{}}, {{m4exit(1)}})dnl
ifdef({{conf_LCD_INLINE}}, {{}}, {{m4exit(1)}})dnl
<html>
<head>
<title>Ethersex - LCD</title>
<link rel="stylesheet" href="Sty.c" type="text/css"/>
<script src="scr.js" type="text/javascript"></script>
<script type="text/javascript">
ifdef({{conf_HD44780_BACKLIGHT}}, {{dnl
function fillFields() {
	getCmd('lcd+backlight', parseResponse, $('backlight'));
}

function getCmd(cmd, handler, data) {
	ArrAjax.ecmd(cmd, handler, 'GET', data);
}

function parseResponse(request, data) {
	var is_checked = (request.responseText == "on\n") ? true : false;
	var obj = document.getElementById(data.id);
	obj.checked = is_checked;
}

function set_backlight(value) {
	var state = (value) ? "on" : "off";
	ArrAjax.ecmd('lcd+backlight+' + state);
}
}})dnl
function ecmd(cmd) {
	ArrAjax.ecmd(cmd);
}
</script>
</head>
ifdef({{conf_HD44780_BACKLIGHT}}, {{dnl
<body onLoad='fillFields()'>
}}, {{dnl
<body>
}})dnl
<h1>LCD</h1>
<form action="?" name="form">
<input type="text" name="msg"> <input type="button" value="write" onclick="ecmd('lcd+write+'+window.document.form.msg.value.replace(/ /g,'+'))"> <input type="button" value="clear" onclick="ecmd('lcd+clear')"><br>
<input type="button" value="test" onclick="ecmd('lcd+write+hello+world')"><br>
<label>
<input type="checkbox" id="backlight" name="backlight" value="backlight_v" onChange="set_backlight(this.checked)">
Backlight
</label>
</form>
<br>
<br>
<a href="idx.ht"> Back </a>
<div id="logconsole"></div>
</body>
</html>
