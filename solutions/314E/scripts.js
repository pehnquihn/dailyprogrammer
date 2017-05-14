
function process_input () {

	function repeat (string, times) {
		var result = '';
		for (var i = 0; i < times; i++)
			result += string;
		return result;
	}

	function Elem (orig, sort) {
		this.orig = orig;
		this.sort = sort;
	}

	var input = document.forms['main_input']['input'].value.split(' ');
	var max_len = input.reduce(function (max, num) {
		return Math.max(max, num.length);
	}, 0);
	input = input.map(function (elem) {
		var sort_num = Number(elem + repeat(elem.charAt(elem.length - 1), max_len - elem.length));
		return new Elem(elem, sort_num);
	});
	input.sort(function (a, b) {
		return a.sort - b.sort;
	});
	var max_copy = input.slice(), min_copy = input.slice();
	var max = '';
	while (max_copy.length)
		max += max_copy.pop().orig;
	var min = '';
	while (min_copy.length)
		min += min_copy.shift().orig;
	var result_text = 'Min: ' + min + '\tMax: ' + max;
	var result = document.getElementById('answer').textContent = result_text;
}

