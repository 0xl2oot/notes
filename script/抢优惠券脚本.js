$(".J-gotoAuth").removeAttr("disabled");  // 去掉领取按钮禁用属性
var a=setInterval("beatall()","100");
function beatall() {
	$(document).ready(function(){
		$(".J-gotoAuth").trigger("click");
			switch($('strong:eq(5)').text()){
			case "温馨提示":
				console.log($('.tips').text());
			switch($('.tips').text()){
			case "尊敬的用户，今天的代金券已抢完，请明天再来。":
				clearInterval(a);
				console.log("代金卷已抢完,停止运行");
			break;
			case "尊敬的用户，本月您已领取优惠代金券，请下个月再领取。":
				clearInterval(a);
				console.log("本月您已领取优惠代金券,已停止");
			break;
			default:}
			break;
			case "领取成功":
				clearInterval(a);
				console.log("领取成功,已停止运行");
			break;
			case "学生认证":
				console.log($('.tips').text());
				clearInterval(a);
				console.log("已停止运行");
			break;
			default:}
		$(".J-btnConfirm").trigger("click");
	});
}