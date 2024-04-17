/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Dictionary;
import java.util.*;
/**
 *
 * @author kyleh
 */
public enum Dictionary {
    
ArrowNoun("arrow", "noun", "Here is one arrow: <IMG> -=>> </IMG>"), 
     
    BNoun1("Book", "noun", "A set of pages."), 
    BNoun2("Book", "noun", "A written work published in printed or electronic form."), 
    BVerb1("Book", "verb", "To arrange for someone to have a seat on a plane."), 
    BVerb2("Book", "verb", "To arrange for something on a particular date."), 
     
    CSC220Adjective("CSC220", "adjective", "Ready to create complex data structures."), 
    CSC220Verb("CSC220", "verb", "To create data structures."), 
     
    CSC340Adjective("CSC340", "adjective", "= C++ version of CSC210 + CSC220 + more."), 
    CSC340Noun1("CSC340", "noun", "A CS upper division course."), 
    CSC340Noun2("CSC340", "noun", "Many hours outside of class."), 
    CSC340Noun3("CSC340", "noun", "Programming Methodology."), 
     
    DAdjective1("Distinct", "adjective", "Familiar. Worked in Java."), 
    DAdjective2("Distinct", "adjective", "Unique. No duplicates. Clearly different or of a different kind."), 
    DAdverb1("Distinct", "adverb", "Uniquely. Written \"distinctly\"."), 
    DNoun1("Distinct", "noun", "A keyword in this assignment."), 
    DNoun2("Distinct", "noun", "A keyword in this assignment."), 
    DNoun3("Distinct", "noun", "A keyword in this assignment."), 
    DNoun4("Distinct", "noun", "An advanced search option."), 
    DNoun5("Distinct", "noun", "Distinct is a parameter in this assignment."), 
     
     
    PAdjective1("Placeholder", "adjective", "To be updated..."), 
    PAdjective2("Placeholder", "adjective", "To be updated..."), 
    PAdverb3("Placeholder", "adverb", "To be updated..."), 
    PConjunction("Placeholder", "conjunction", "To be updated..."), 
    PInterjection("Placeholder", "interjection", "To be updated..."), 
    PNoun1("Placeholder", "noun", "To be updated..."), 
    PNoun2("Placeholder", "noun", "To be updated..."), 
    PNoun3("Placeholder", "noun", "To be updated..."), 
    PPreposition("Placeholder", "preposition", "To be updated..."), 
    PPronoun("Placeholder", "pronoun", "To be updated..."), 
    PVerb("Placeholder","verb", "To be updated..."), 
    
    RAdjective1("Reverse", "adjective", "On back side"), 
    RAdjective2("Reverse", "adjective", "Opposite to usual or previous arrangement"),
    RNoun1("Reverse", "noun", "A dictionary program's parameter."), 
    RNoun2("Reverse", "noun", "A opposite."), 
    RNoun3("Reverse", "noun", "To be updated..."), 
    RNoun4("Reverse", "noun", "To be updated..."), 
    RNoun5("Reverse", "noun", "To be updated..."),
    RNoun6("Reverse", "noun", "To be updated..."),
    RVerb1("Reverse","verb", "Change something to opposite."),
    RVerb2("Reverse","verb", "Go back."),
    RVerb3("Reverse","verb", "Revoke ruling."),
    RVerb4("Reverse","verb", "To be updated..."),
    RVerb5("Reverse","verb", "To be updated..."),
    RVerb6("Reverse","verb", "Turn something inside out"),
    
    
   ENoun1("Energy", "noun", "The capacity for vigorous activity."),
   ENoun2("Energy", "noun", "An adequate or abundant amount of such power."),
   ENoun3("Energy", "noun", "A feeling of tension caused or seeming to be caused by an excess of such power."),
   ENoun4("Energy", "noun", "An exertion of  such power"),
   ENoun5("Energy", "noun", "The habit of vigorous activity"),
   ENoun6("Energy", "noun", "The ability to act, lead others, effect,etc"),
   EAdjective1("Energy", "adjective", "To be updated..."),
   EAdverb("Energy", "adverb", "To be updated..."),
   EConjunction("Energy", "conjunction", "To be updated..."), 
   EInterjection("Energy", "interjection", "To be updated..."),
 
    AdverbNoun("Adverb", "noun", "Adverb is a word that adds more information about place, time, manner, cause or\n" + 
"degree to a verb, an adjective, a phrase or another adverb."), 
    Adjective("Adjective", "noun", "Adjective is a word that describes a person or thing, for example big, red and\n clever in a big house, red wine and a clever idea."), 
    Interjection("Interjection", "noun", "Interjection is a short sound, word or phrase spoken suddenly to express an\n" + 
"emotion. Oh!, Look out! and Ow! are interjections."), 
    NounNoun("Noun", "noun", "Noun is a word that refers to a person, (such as Ann or doctor), a place (such as Paris\n or city) or a thing, a quality or an activity (such as plant, sorrow or tennis."); 
 
     
 
    private final String def = "Definition"; 
     
    private String Keyword; 
     
    private String PartOfSpeech; 
     
    private  String Definition; 
 
    //Creates
    //Constructor for Dictionary
     
     private Dictionary(String KeyWord, String PartOfSpeech, String Definition) { 
 
        this.Keyword = KeyWord; 
 
        this.PartOfSpeech = PartOfSpeech; 
 
        this.Definition = Definition; 
 
    } 
      
    public String getkeyword() { 
        return this.Keyword.toUpperCase(); 
    } 
 
    public String getpartOfSpeech() { 
        return this.PartOfSpeech; 
    } 
     
    public String getDefinition() { 
        return this.Definition;  
    } 
     
    public void setDefinition(String Definition) { 
 
        this.Definition = Definition; 
 
    } 
 
    public String toString() { 
        return this.Keyword + " [" + this.PartOfSpeech + "]" + " : " + this.Definition; 
    } 
 
    
    //Main Interface of Dictionary
    public static void main(String[] args) { 
        System.out.println("! Loading data..."); 
        Scanner input = new Scanner(System.in); 
        
        HashMap<String, ArrayList<Dictionary>> hmap = new HashMap<>(); 
        
        for (Dictionary use  : Dictionary.values()) { 
  
                String keyword = use.getkeyword(); 

                ArrayList<Dictionary> list = (hmap.containsKey(keyword)) ? hmap.get(keyword) : new ArrayList<>(); 
                list.add(use); 
                hmap.put(keyword, list);		 
        } 
 
        System.out.println("! Loading Complete..."); 
        System.out.println(); 
        System.out.println("\n-----DICTIONARY 340 JAVA-----\n"); 
        System.out.println(); 
 
        Boolean exit = true; 
 
        do{ 
             
            System.out.print("Search: "); 
            String userinput = input.nextLine().toLowerCase(); 
             
            String[] SplitSearch = userinput.split(" "); 
            
            String term = null;   
             
            Boolean seekDistinct = false; 
             
            String partOfSpeech = null; 
 
            if (SplitSearch.length > 0) { 
                term = SplitSearch[0]; 
                 
            } 
             
            String[] partOfSpeeches = {"adjective", "adverb", "noun", "verb", "pronoun", "preposition", "conjunction", "interjection"}; 
             if (SplitSearch.length > 1 && SplitSearch[1]!= null) { 
                if (SplitSearch[1].equalsIgnoreCase("distinct")) { 
                    seekDistinct = true; 
                }  
                else if (Arrays.asList(partOfSpeeches).contains(SplitSearch[1].toLowerCase())){ 
                    partOfSpeech = SplitSearch[1]; 
                }  
                else { 
                    System.out.println("   |"); 
                    System.out.println("    <2nd argument must be a part of speech or \"distinct\">"); 
                    System.out.println("   |"); 
                     
                } 
            } 
            if (SplitSearch.length > 2) { 
                if (SplitSearch[2]!= null) { 
                    if (SplitSearch[2].equalsIgnoreCase("distinct")) { 
                        seekDistinct = true; 
                    } else if (!Arrays.asList(partOfSpeeches).contains(SplitSearch[2].toLowerCase())){ 
                        System.out.println("   |"); 
                        System.out.println("    <2nd argument must be a part of speech or \"distinct\">"); 
                        System.out.println("   |"); 
                        continue; 
                    } else { 
                        partOfSpeech = SplitSearch[2]; 
                    } 
                } 
            } 
                        
            if(!userinput.equalsIgnoreCase("!Q")) { 
                System.out.println("   |"); 
                var outcome = hmap.get(term.toUpperCase()); 
                ArrayList<Dictionary> nextOutcome = (seekDistinct) ? returnDictionaryWithDistinctPartOfSpeech(outcome) : outcome; 
                ArrayList<Dictionary> lastOutcome = (partOfSpeech != null) ? returnDictionaryWithSamePartOfSpeech(nextOutcome, partOfSpeech) : nextOutcome; 
 
                if (lastOutcome != null && lastOutcome.size()>0) { 
                    lastOutcome.forEach((list) -> { 
                        System.out.print(list + "    " + "\n"); 
                    }); 
                } else { 
                    System.out.println("    <Not Found>"); 
                } 
                System.out.println("   |"); 
            } else { 
                System.out.println("\n-----Thank You-----"); 
                exit = false; 
            } 
        } while(exit); 
    } 
         
    public static ArrayList<Dictionary> returnDictionaryWithDistinctPartOfSpeech(ArrayList<Dictionary> List) { 
        HashMap<String, Dictionary> hMap = new HashMap<>(); 
        if (List != null) { 
            List.forEach((search) -> { 
                String partOfSpeech = search.getpartOfSpeech(); 
                if (!hMap.containsKey(partOfSpeech)) { 
                    hMap.put(partOfSpeech, search); 
                } 
            }); 
        } 
        return new ArrayList<>(hMap.values()); 
    } 
    
    public static ArrayList<Dictionary> returnDictionaryWithSamePartOfSpeech(ArrayList<Dictionary> List, String partOfSpeech) { 
        ArrayList<Dictionary> result = new ArrayList<>(); 
        if (List != null) { 
            List.stream().filter((search) -> (search.getpartOfSpeech().equalsIgnoreCase(partOfSpeech))).forEachOrdered((search) -> { 
                result.add(search); 
            }); 
        } 
        return result; 
    } 
 
     
    }










