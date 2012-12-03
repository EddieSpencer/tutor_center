all: Interface_Driver.cpp Interface.cpp Feedback.cpp ProgressReport.cpp User.cpp Student.cpp Time.cpp Tutor.cpp LinkedList.cpp Meeting.cpp Admin.cpp MeetingList.cpp PointerLinkedList.cpp
	g++ Interface_Driver.cpp Interface.cpp Feedback.cpp ProgressReport.cpp User.cpp Student.cpp Time.cpp Tutor.cpp LinkedList.cpp Meeting.cpp Admin.cpp MeetingList.cpp PointerLinkedList.cpp -o tutorsys
	./tutorsys