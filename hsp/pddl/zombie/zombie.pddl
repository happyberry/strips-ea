(define (domain zombie)
	(:requirements :strips)
	(:predicates
		(location ?x)
		(enemy ?x)
		(bigenemy ?x)
		(character ?x)
		(item ?x)

		(at ?x ?y)
		(has ?x ?y)
		(safe ?x)
		(cured ?x)
		(fed ?x)
		(healthy ?x)
		(infected ?x)
		(path ?x ?y)
		(open ?x)
		(hero ?x)
		(alive ?x)
		(istool ?x)
		(iswood ?x)
		(isbridge ?x)
		(isantidote ?x)
		(isfood ?x)
		(iskey ?x ?y)
		(starving ?x)
		(knowneed ?x ?y ?z))
		
		(:action go
		:parameters ( ?c ?l1 ?l2)
		:precondition (and	(character ?c)
					(location ?l1)
					(location ?l2)
					(at ?c ?l1)
					(alive ?c)
					(hero ?c)
					(open ?l1)
					(path ?l1 ?l2))
		:effect (and		(at ?c ?l2)
					(not (at ?c ?l1))))
		(:action get
		:parameters ( ?c ?i ?l)
		:precondition (and	(character ?c)
					(item ?i)
					(location ?l)
					(at ?c ?l)
					(alive ?c)
					(hero ?c)
					(at ?i ?l)
					(safe ?l))
		:effect (and		(has ?c ?i)
					(not (at ?i ?l))))
		(:action ask
		:parameters ( ?c1 ?c2 ?i ?l)
		:precondition (and	(character ?c1)
					(character ?c2)
					(item ?i)
					(location ?l)
					(at ?c1 ?l)
					(alive ?c1)
					(hero ?c1)
					(healthy ?c2)
					(at ?c2 ?l)
					(has ?c2 ?i))
		:effect (and		(knowneed ?c2 ?c1 ?i)))
		(:action give
		:parameters ( ?c1 ?c2 ?i ?l)
		:precondition (and	(character ?c1)
					(character ?c2)
					(item ?i)
					(location ?l)
					(at ?c1 ?l)
					(alive ?c1)
					(hero ?c1)
					(healthy ?c2)
					(at ?c2 ?l)
					(has ?c1 ?i)
					(knowneed ?c2 ?c1 ?i))
		:effect (and		(has ?c2 ?i)
					(not (has ?c1 ?i))))
		(:action fixbridge
		:parameters ( ?c ?i1 ?i2 ?l)
		:precondition (and	(character ?c)
					(item ?i1)
					(item ?i2)
					(location ?l)
					(at ?c ?l)
					(alive ?c)
					(hero ?c)
					(isbridge ?l)
					(istool ?i1)
					(iswood ?i2)
					(has ?c ?i1)
					(has ?c ?i2))
		:effect (and		(open ?l)
					(not (has ?c ?i2))))
		(:action opendoor
		:parameters ( ?c ?i ?l)
		:precondition (and	(character ?c)
					(item ?i)
					(location ?l)
					(at ?c ?l)
					(alive ?c)
					(hero ?c)
					(iskey ?i ?l)
					(has ?c ?i))
		:effect (and		(open ?l)
					(not (has ?c ?i))))
		(:action attack
		:parameters ( ?e ?c ?l)
		:precondition (and	(enemy ?e)
					(character ?c)
					(location ?l)
					(at ?c ?l)
					(alive ?c)
					(healthy ?c))
		:effect (and		(infected ?c)
					(not (healthy ?c))))
		(:action cure
		:parameters ( ?c1 ?c2 ?i ?l)
		:precondition (and	(character ?c1)
					(character ?c2)
					(item ?i)
					(location ?l)
					(at ?c1 ?l)
					(alive ?c1)
					(hero ?c1)
					(at ?c2 ?l)
					(alive ?c2)
					(infected ?c2)
					(has ?c1 ?i)
					(isantidote ?i)
					(not (= ?c1 ?c2)))
		:effect (and		(cured ?c2)
					(healthy ?c2)
					(not (infected ?c2))
					(not (has ?c1 ?i))))
		(:action starve
		:parameters ( ?c ?l)
		:precondition (and	(character ?c)
					(location ?l)
					(at ?c ?l)
					(alive ?c)
					(healthy ?c))
		:effect (and		(starving ?c)
					(not (healthy ?c))))
		(:action feed
		:parameters ( ?c1 ?c2 ?i ?l)
		:precondition (and	(character ?c1)
					(character ?c2)
					(item ?i)
					(location ?l)
					(at ?c1 ?l)
					(alive ?c1)
					(hero ?c1)
					(at ?c2 ?l)
					(alive ?c2)
					(starving ?c2)
					(has ?c1 ?i)
					(isfood ?i)
					(not (= ?c1 ?c2)))
		:effect (and		(fed ?c2)
					(healthy ?c2)
					(not (starving ?c2))
					(not (has ?c1 ?i))))
		(:action kill
		:parameters ( ?c ?e ?l)
		:precondition (and	(character ?c)
					(bigenemy ?e)
					(location ?l)
					(at ?c ?l)
					(alive ?c)
					(hero ?c))
		:effect (and		(safe ?l))))