import queue as Q

class Skill(object):
	def __init__(self, priority, description):
		self.priority = priority
		self.description = description
		print "New level: ", description
		return
	def __cmp__(self, other):
		return cmp(self.description, other.description)

me = Skill(5, "Intermediate")
you = Skill(10, "Expert")
she = Skill(25, "Master")

q = Q.PriorityQueue()

q.put(me)
q.put(you)
q.put(she)


while not q.empty():
	next_level = q.get()
	print 'Processing level:', next_level.description