extends Node

func _ready():
	var simple = load("res://simple.gdns").new()
	simple.say(simple.hello("World"))