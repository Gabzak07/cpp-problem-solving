# VR_Participant_List

Manages an alphabetically sorted list of event participants by first sorting the initial entries, removing dropouts based on their list position, and finally inserting new participants while maintaining the alphabetical order.

Input: `Duomenys.txt` — initial number of participants and their names, followed by a zero-terminated list of dropout indices, and a count with names of new participants to insert.  
Output: `Rezultatas.txt` — the participant list displayed at three stages: initially sorted, after dropouts are removed, and after new participants are added.