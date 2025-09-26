import wolframalpha
import pyttsx3
import speech_recognition 

engine = pyttsx3.init("sapi5")
voices = engine.getProperty("voices")
engine.setProperty("voice", voices[0].id)
rate = engine.setProperty("rate",170)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def takeCommand():
    r = speech_recognition.Recognizer()
    with speech_recognition.Microphone() as source:
        print("Listening.....")
        r.pause_threshold = 20
        r.energy_threshold = 189
        audio = r.listen(source,0,4)

    try:
        print("Understanding..")
        query  = r.recognize_google(audio,language='en-in')
        print(f"You Said: {query}\n")
        return query
    except Exception as e:
        print("Say that again")
        return "None"

def WolfRamAlpha(query):
    apikey = "8TVK64-TYQEV7QW75"
    requester = wolframalpha.Client(apikey)
    requested = requester.query(query)

    try:
        answer = next(requested.results).text
        return answer
    except:
        speak("The value is not answerable")

def Calc():
    while True:
             query = takeCommand().lower()
             Term = str(query)
             Term = Term.replace("jarvis","")
             Term = Term.replace("multiply","*")
             Term = Term.replace("plus","+")
             Term = Term.replace("minus","-")
             Term = Term.replace("divide","/")

             Final = str(Term)
             result = WolfRamAlpha(Final)
             print(f"{result}")
             speak(result)
if __name__ == "__main__":
     Calc()