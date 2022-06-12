(define (problem zombie_17)
	(:domain zombie)
	(:objects john anne maggie rick bob matt robin
	 forest vilage johnhouse neighborhouse hospital hospitaldoor store vilageislandbridge island islandwest islandeast islandmountainbridge mountain mountainwest mountaineast
	 antidote1 antidote2 antidote3 antidote4 antidote5 wood1 wood2 wood3 wood4 hospitalkey toolkit1 toolkit2 food1 food2 food3 food4 food5
	 zombie
	 bigzombie
	)
	(:init	(character john)
		(character anne)
		(character maggie)
		(character rick)
		(character bob)
		(character matt)
		(character robin)
		(location forest)
		(location vilage)
		(location johnhouse)
		(location neighborhouse)
		(location hospital)
		(location hospitaldoor)
		(location store)
		(location vilageislandbridge)
		(location island)
		(location islandwest)
		(location islandeast)
		(location islandmountainbridge)
		(location mountain)
		(location mountainwest)
		(location mountaineast)
		(item antidote1)
		(item antidote2)
		(item antidote3)
		(item antidote4)
		(item antidote5)
		(item wood1)
		(item wood2)
		(item wood3)
		(item wood4)
		(item hospitalkey)
		(item toolkit1)
		(item toolkit2)
		(item food1)
		(item food2)
		(item food3)
		(item food4)
		(item food5)
		(enemy zombie)
		(bigenemy bigzombie)
		(path johnhouse vilage)
		(path vilage johnhouse)
		(path forest vilage)
		(path vilage forest)
		(path neighborhouse vilage)
		(path vilage neighborhouse)
		(path hospitaldoor vilage)
		(path vilage hospitaldoor)
		(path hospitaldoor hospital)
		(path hospital hospitaldoor)
		(path store vilage)
		(path vilage store)
		(path vilageislandbridge vilage)
		(path vilage vilageislandbridge)
		(path vilageislandbridge island)
		(path island vilageislandbridge)
		(path island islandwest)
		(path islandwest island)
		(path island islandeast)
		(path islandeast island)
		(path island islandmountainbridge)
		(path islandmountainbridge island)
		(path mountain islandmountainbridge)
		(path islandmountainbridge mountain)
		(path mountain mountainwest)
		(path mountainwest mountain)
		(path mountain mountaineast)
		(path mountaineast mountain)
		(open forest)
		(open vilage)
		(open johnhouse)
		(open neighborhouse)
		(open hospital)
		(open store)
		(open island)
		(open islandwest)
		(open islandeast)
		(open mountain)
		(open mountainwest)
		(open mountaineast)
		(safe johnhouse)
		(safe neighborhouse)
		(safe hospital)
		(safe store)
		(hero john)
		(alive john)
		(alive anne)
		(alive maggie)
		(alive rick)
		(alive bob)
		(alive matt)
		(alive robin)
		(healthy john)
		(healthy anne)
		(healthy maggie)
		(healthy rick)
		(healthy bob)
		(healthy matt)
		(healthy robin)
		(at john johnhouse)
		(at anne johnhouse)
		(at maggie johnhouse)
		(at rick store)
		(at bob hospital)
		(at matt islandeast)
		(at robin mountainwest)
		(istool toolkit1)
		(istool toolkit2)
		(iswood wood1)
		(iswood wood2)
		(iswood wood3)
		(iswood wood4)
		(isbridge vilageislandbridge)
		(isbridge islandmountainbridge)
		(isantidote antidote1)
		(isantidote antidote2)
		(isantidote antidote3)
		(isantidote antidote4)
		(isantidote antidote5)
		(isfood food1)
		(isfood food2)
		(isfood food3)
		(isfood food4)
		(isfood food5)
		(iskey hospitalkey hospitaldoor)
		(at food1 mountainwest)
		(at wood1 forest)
		(at hospitalkey forest)
		(at antidote2 hospital)
		(has bob antidote3)
		(has rick food2)
		(at food3 hospital)
		(at wood2 islandeast)
		(infected john)
		(safe neighborhouse)
		(fed anne)
		(safe islandeast)
		(safe islandeast)
		(has matt antidote4)
		(has rick wood3)
		(healthy maggie)
		(healthy robin)
		(has john wood4)
		(healthy bob)
		(safe vilage)
		(has robin antidote2)
		(safe mountaineast)
		(safe islandeast)
		(safe island)
		(at toolkit1 vilageislandbridge)
		(cured rick)
		(at maggie vilage)
		(cured matt)
		(cured bob)
		(at antidote5 mountainwest)
		(safe mountain)
		(fed matt)
		(healthy bob)
		(fed john)
		(at food4 hospital)
		(infected anne)
		(cured bob)
		(fed robin)
		(healthy matt)
		(safe store)
		(at antidote3 neighborhouse)
		(healthy robin)
		(cured bob)
		(healthy matt)
		(has anne antidote5)
		(has robin antidote1)
		(at matt store)
		(safe store)
		(cured robin)
		(safe islandeast)
		(has robin food4)
		(healthy maggie)
		(cured matt)
		(safe forest)
		(has maggie toolkit1)
		(fed matt)
		(fed anne)
		(has matt food3)
		(fed matt)
		(cured anne)
		(has anne wood1)
		(has matt food5)
		(safe mountaineast)
		(fed robin)
		(fed maggie)
		(cured robin)
		(safe neighborhouse)
		(safe forest)
		(at antidote1 store)
		(cured anne)
		(safe johnhouse)
		(cured anne)
		(cured bob)
		(healthy robin)
		(healthy maggie)
		(healthy rick)
		(cured rick)
		(fed john)
		(at rick johnhouse)
		(has anne hospitalkey)
		(safe neighborhouse)
		(fed robin)
		(fed bob)
		(safe mountaineast)
		(at food2 vilageislandbridge)
		(healthy robin)
		(safe islandeast)
		(healthy maggie)
		(safe johnhouse)
		(cured rick)
		(cured matt)
		(safe mountaineast)
		(safe vilage)
		(has robin food1)
		(cured john)
		(at wood4 hospitaldoor)
		(cured bob)
		(healthy bob)
		(safe hospital)
		(fed anne)
		(cured rick)
		(safe mountainwest)
		(healthy matt)
		(safe mountainwest)
		(safe hospitaldoor)
		(safe forest)
		(cured robin)
		(fed john)
		(fed john)
		(infected anne)
		(cured anne)
		(healthy bob)
		(fed robin)
		(cured bob)
		(fed robin)
		(cured robin)
		(safe vilageislandbridge)
		(safe forest)
		(cured maggie)
		(fed anne)
		(healthy maggie)
		(cured anne)
		(fed anne)
		(fed matt)
		(fed rick)
		(at wood3 islandeast)
		(fed maggie)
		(infected matt)
		(healthy bob)
		(fed matt)
		(safe neighborhouse)
		(safe vilage)
		(healthy maggie))

	(:goal (and	(path johnhouse vilage)
		(path vilage johnhouse)
		(path forest vilage)
		(path vilage forest)
		(path neighborhouse vilage)
		(path vilage neighborhouse)
		(path hospitaldoor vilage)
		(path vilage hospitaldoor)
		(path hospitaldoor hospital)
		(path hospital hospitaldoor)
		(path store vilage)
		(path vilage store)
		(path vilageislandbridge vilage)
		(path vilage vilageislandbridge)
		(path vilageislandbridge island)
		(path island vilageislandbridge)
		(path island islandwest)
		(path islandwest island)
		(path island islandeast)
		(path islandeast island)
		(path island islandmountainbridge)
		(path islandmountainbridge island)
		(path mountain islandmountainbridge)
		(path islandmountainbridge mountain)
		(path mountain mountainwest)
		(path mountainwest mountain)
		(path mountain mountaineast)
		(path mountaineast mountain)
		(open forest)
		(open vilage)
		(open johnhouse)
		(open neighborhouse)
		(open hospital)
		(open store)
		(open island)
		(open islandwest)
		(open islandeast)
		(open mountain)
		(open mountainwest)
		(open mountaineast)
		(safe johnhouse)
		(safe neighborhouse)
		(safe hospital)
		(safe store)
		(hero john)
		(alive john)
		(alive anne)
		(alive maggie)
		(alive rick)
		(alive bob)
		(alive matt)
		(alive robin)
		(healthy john)
		(healthy anne)
		(healthy maggie)
		(healthy rick)
		(healthy bob)
		(healthy matt)
		(healthy robin)
		(at john johnhouse)
		(at anne johnhouse)
		(at maggie johnhouse)
		(at rick store)
		(at bob hospital)
		(at matt islandeast)
		(at robin mountainwest)
		(istool toolkit1)
		(istool toolkit2)
		(iswood wood1)
		(iswood wood2)
		(iswood wood3)
		(iswood wood4)
		(isbridge vilageislandbridge)
		(isbridge islandmountainbridge)
		(isantidote antidote1)
		(isantidote antidote2)
		(isantidote antidote3)
		(isantidote antidote4)
		(isantidote antidote5)
		(isfood food1)
		(isfood food2)
		(isfood food3)
		(isfood food4)
		(isfood food5)
		(iskey hospitalkey hospitaldoor)
		(at food1 mountainwest)
		(at wood1 forest)
		(at hospitalkey forest)
		(at antidote2 hospital)
		(has bob antidote3)
		(has rick food2)
		(at food3 hospital)
		(at wood2 islandeast)
		(infected john)
		(safe neighborhouse)
		(fed anne)
		(safe islandeast)
		(safe islandeast)
		(has matt antidote4)
		(has rick wood3)
		(healthy maggie)
		(healthy robin)
		(has john wood4)
		(healthy bob)
		(safe vilage)
		(has robin antidote2)
		(safe mountaineast)
		(safe islandeast)
		(safe island)
		(at toolkit1 vilageislandbridge)
		(cured rick)
		(at maggie vilage)
		(cured matt)
		(cured bob)
		(at antidote5 mountainwest)
		(safe mountain)
		(fed matt)
		(healthy bob)
		(fed john)
		(at food4 hospital)
		(infected anne)
		(cured bob)
		(fed robin)
		(healthy matt)
		(safe store)
		(at antidote3 neighborhouse)
		(healthy robin)
		(cured bob)
		(healthy matt)
		(has anne antidote5)
		(has robin antidote1)
		(at matt store)
		(safe store)
		(cured robin)
		(safe islandeast)
		(has robin food4)
		(healthy maggie)
		(cured matt)
		(safe forest)
		(has maggie toolkit1)
		(fed matt)
		(fed anne)
		(has matt food3)
		(fed matt)
		(cured anne)
		(has anne wood1)
		(has matt food5)
		(safe mountaineast)
		(fed robin)
		(fed maggie)
		(cured robin)
		(safe neighborhouse)
		(safe forest)
		(at antidote1 store)
		(cured anne)
		(safe johnhouse)
		(cured anne)
		(cured bob)
		(healthy robin)
		(healthy maggie)
		(healthy rick)
		(cured rick)
		(fed john)
		(at rick johnhouse)
		(has anne hospitalkey)
		(safe neighborhouse)
		(fed robin)
		(fed bob)
		(safe mountaineast)
		(at food2 vilageislandbridge)
		(healthy robin)
		(safe islandeast)
		(healthy maggie)
		(safe johnhouse)
		(cured rick)
		(cured matt)
		(safe mountaineast)
		(safe vilage)
		(has robin food1)
		(cured john)
		(at wood4 hospitaldoor)
		(cured bob)
		(healthy bob)
		(safe hospital)
		(fed anne)
		(cured rick)
		(safe mountainwest)
		(healthy matt)
		(safe mountainwest)
		(safe hospitaldoor)
		(safe forest)
		(cured robin)
		(fed john)
		(fed john)
		(infected anne)
		(cured anne)
		(healthy bob)
		(fed robin)
		(cured bob)
		(fed robin)
		(cured robin)
		(safe vilageislandbridge)
		(safe forest)
		(cured maggie)
		(fed anne)
		(healthy maggie)
		(cured anne)
		(fed anne)
		(fed matt)
		(fed rick)
		(at wood3 islandeast)
		(fed maggie)
		(infected matt)
		(healthy bob)
		(fed matt)
		(safe neighborhouse)
		(safe vilage)
		(healthy maggie))))