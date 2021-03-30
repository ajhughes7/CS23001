/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2019 Kent State University. All rights reserved.
 *  Fall 2019
 *  Modified by:
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(const std::vector<std::string>& profileName) {
    tree->mainHeader(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}


/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profileName) {
    tree->funcCount(profileName);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each condition.
//
void srcML::condCount(const std::string& profileName) {
    tree->condCount(profileName);
}

    

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}

AST::AST(nodes t, const std::string& s, std::list<AST*> children) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
    child = children;
}


/////////////////////////////////////////////////////////////////////
// Destructor for AST

// using range-based for loop
// https://stackoverflow.com/a/24195473/12105050

AST::~AST() {
  for(auto&& c : child) {
    delete c;
  }
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
  text = actual.text;
  closeTag = actual.closeTag;
  tag = actual.tag;
  nodeType = actual.nodeType;
  //Recursively traverse actual and
  //make a copy of each node putting it
  //into this.
  for(auto c : actual.child) {
    child.push_back(new AST(*c));
  }
}


/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& b) {
  // nodeType swap
  nodes tmpNodeType = nodeType;
  nodeType = b.nodeType;
  b.nodeType = tmpNodeType;
  // tag swap
  std::string tmpTag = tag; 
  tag = b.tag;
  b.tag = tmpTag;
  // closeTag swap
  std::string tmpCloseTag = closeTag;
  closeTag = b.closeTag;
  b.closeTag = tmpCloseTag;
  // text swap
  std::string tmpText = text;
  text = b.text;
  b.text = tmpText; 
  // child swap
  child.swap(b.child);
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for milestone 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//  There are two types of names.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from an AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


void AST::addProfileInclude(std::list<AST*>::iterator itr) {

  /*  <cpp:include>
        #<cpp:directive>include</cpp:directive> 
        <cpp:file>"profile.hpp"</cpp:file>
      </cpp:include>  
   */

  //  #include "profile.hpp"

  std::list<AST*> includeList = {
    new AST(token, "#"),
    new AST(category, "cpp:directive", {
	    new AST(token, "include"),
	    new AST(whitespace, " ")    
      }),
    new AST(category, "cpp:file", {    
	new AST(token, "\"profile.hpp\""),
	new AST(whitespace, "\n")  
      }),
  };
  AST* includeAST = new AST(category, "cpp:include", includeList);
  child.insert(itr, includeAST);  
}


void AST::addProfileDeclaration(std::list<AST*>::iterator itr, std::string profileObjectName) {

  //  profile main1_cpp("main1.cpp"); 

  /* 

<decl_stmt>
  <decl>
    <type>
      <name>profile</name>
    </type>
    <name>main1_cpp</name>
    <argument_list>(<argument>
    <expr>"main1.cpp"</expr>
    </argument>)</argument_list>
  </decl>;
</decl_stmt>
  */

  std::string profileParamName = profileObjectName;
  std::replace(profileParamName.begin(), profileParamName.end(), '_', '.'); 
  std::list<AST*> directiveList = {
    new AST(category, "decl", {
	new AST(category, "type", {
	    new AST(category, "name", {
		new AST(token, "profile")
		  })}),
	  new AST(whitespace, " "),
	  new AST(category, "name", {
	      new AST(token, profileObjectName)
		}),
	  new AST(category, "argument_list", {
	      new AST(token, "("),
		new AST(category, "argument", {
		    new AST(category, "expr", {
			new AST(token, "\"" + profileParamName +"\"")
			  })
		      }),
		new AST(token, ")")
		}),
	  new AST(token, ";"),
	  new AST(whitespace, "\n")
	  })};
  AST* directiveAST = new AST(category, "decl_stmt", directiveList);
  child.insert(itr, directiveAST);
}



/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(const std::vector<std::string>& profileName) {
  std::list<AST*>::iterator itr = child.begin();
  iterateToBefore(itr, "function");
  addProfileInclude(itr);

  for(std::vector<std::string>::const_iterator p = profileName.begin(); p != profileName.end(); ++p) {
    addProfileDeclaration(itr, *p);    
  }     
}

  void AST::addProfileExtern(std::list<AST*>::iterator itr, std::string profileObjectName) {
  /* <decl_stmt>
       <decl>
         <type>
	   <specifier>extern</specifier> 
	   <name>profile</name>
	 </type> 
	 <name>foo_cpp</name>
       </decl>;
      </decl_stmt>
   */

  std::string profileParamName = profileObjectName;
  std::replace(profileParamName.begin(), profileParamName.end(), '_', '.'); 
  std::list<AST*> profileParamList = {
    new AST(category, "decl", {
	new AST(category, "type", {
	    new AST(category, "specifier", {
		new AST(token, "extern")}),
	      new AST(whitespace, " "),
	      new AST(category, "name", {
		  new AST(token, "profile")
		    })}),
	  new AST(whitespace, " "),
	  new AST(category, "name", {
	      new AST(token, profileObjectName)
		}),
	  new AST(token, ";"),
	  new AST(whitespace, "\n")
	  })};
  child.insert(itr, new AST(category, "decl_stmt", profileParamList));

}



/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {
 std::list<AST*>::iterator itr = child.begin();
  iterateToBefore(itr, "function");
  addProfileInclude(itr);  
  addProfileExtern(itr, profileName);
}

// assumes (*this)->tag == "function" 
// returns "" if not found
std::string AST::getFuncName() {
  for (std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
    if ((*i)->tag == "name")
      return (*i)->getName();
  }
  return "";
}
/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(const std::vector<std::string>& profileName) {
  for (std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
    if ((*i)->tag == "function" && (*i)->getFuncName() == "main") { 
      for (std::list<AST*>::iterator j = (*i)->child.begin(); j != (*i)->child.end(); ++j) {
	if ((*j)->tag == "block") {
	  for (std::list<AST*>::iterator k = (*j)->child.end(); k-- != (*j)->child.begin();) {
	    if ((*k)->tag == "return") {
	      for(std::vector<std::string>::const_iterator p = profileName.begin(); p != profileName.end(); ++p) {
		addMainReport(k, *p);
	      }
	    }
	  }
	}
	//Find the main - function with name of "main"
	//Then start from the end() of this function and iterate
	// backwards until you find a return stmt.   You'll want
	// to insert the report statements before this return.	
      }
    }  
  }
}

void AST::addMainReport(std::list<AST*>::iterator itr, std::string profileObjectName) {

  /*     
      <expr_stmt>
	<expr>
	  <name>
	    <name>std</name>::<name>cout</name>
	    </name> &lt;&lt; <name>main1_cpp</name> &lt;&lt; <name>
	    <name>std</name>::<name>endl</name>
	  </name>
      </expr>;</expr_stmt>
   */
  std::list<AST*> exprList = {
		new AST(category, "expr", {
		    new AST(category, "name", {
			new AST(category, "name", {
			    new AST(token, "std")
			      }),
			  new AST (token, "::"),
			  new AST (category, "name", {
			      new AST (token, "cout")
				})}),
		      new AST (whitespace, " "),
		      new AST (token, "<<"),
		      new AST (whitespace, " "),
		      new AST(category, "name", {
			    new AST(token, profileObjectName)
			      }),
		      new AST (whitespace, " "),
		      new AST (token, "<<"),
		      new AST (whitespace, " "),
		      new AST(category, "name", {
			new AST(category, "name", {
			    new AST(token, "std")
			      }),
			  new AST (token, "::"),
			  new AST (category, "name", {
			      new AST (token, "endl")
				})})
		      }),
		new AST (token, ";"),
		new AST (whitespace, "\n"),
		new AST (whitespace, " "),
		new AST (whitespace, " ")
  };			 			  
  child.insert(itr, new AST(category, "expr_stmt", exprList));
} 


/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {   
  for (std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
    std::string curTag = (*i)->tag;
    if (curTag == "function" || 
	curTag == "constructor" ||  
	curTag == "destructor") {
      std::string funcName = "";
      for (std::list<AST*>::iterator j = (*i)->child.begin(); j != (*i)->child.end(); ++j) {
	if ((*j)->tag == "name")
	  funcName = (*j)->getName();
	if ((*j)->tag == "block") {
	  std::list<AST*>::iterator k = (*j)->child.begin();
      	  addFuncCount(++k, profileName, funcName);
	}
      }
    }  
  }
}

void AST::condCount(const std::string& profileName) {  
  for (std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
    if ((*i)->tag == "condition") {
      std::list<AST*>::iterator j = (*i)->child.begin(); 
      if ((*j)->text == "(")
	++j;
      addCondCount(j, profileName); 
}
    if(!isStopTag((*i)->tag))
      (*i)->condCount(profileName);    
  }
}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {  
  for (std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i) {
    if ((*i)->tag == "expr_stmt")
      addLineCount(++i, profileName);
    if(!isStopTag((*i)->tag))
      (*i)->lineCount(profileName);    
  }
}

void AST::addFuncCount(std::list<AST*>::iterator itr, std::string profileObjectName, std::string funcName) {
  addCount(itr, profileObjectName, funcName, ";");
}

void AST::addLineCount(std::list<AST*>::iterator itr, std::string profileObjectName) {
  addCount(itr, profileObjectName, "", ";");
}

void AST::addCondCount(std::list<AST*>::iterator itr, std::string profileObjectName) {
  addCount(itr, profileObjectName, "", ",");
}

void AST::addCount(std::list<AST*>::iterator itr, std::string profileObjectName, std::string funcName, std::string semiOrComma) {

  // main1_cpp.count(__LINE__); 
  /* 

<expr_stmt>
  <expr>
    <call>
      <name>
	<name>main1_cpp</name>.<name>count</name>
      </name>
      <argument_list>(<argument>
      <expr>
	<name>__LINE__</name>
      </expr>
      </argument>)</argument_list>
    </call>
</expr>;</expr_stmt>     

  */
  std::string profileParamName = profileObjectName;
  std::replace(profileParamName.begin(), profileParamName.end(), '_', '.'); 
  std::list<AST*> argList;
  if (funcName == "")
    argList = {
      new AST(category, "argument_list", {
	  new AST(token, "("),
      new AST(category, "argument", {	  
	  new AST(category, "expr", {
	      new AST(category, "name", {
		  new AST(token, "__LINE__")
		    })})}),
		    new AST(token, ")")
	    })
    };
  else 
    argList = {
      new AST(category, "argument_list", {
	  new AST(token, "("),
	    new AST(category, "argument", {
		new AST(category, "expr", {
		    new AST(category, "name", {
			new AST(token, "__LINE__")
			  })})}),
	    new AST(token, ","),
	    new AST(category, "argument", {
		new AST(category, "expr", {
		    new AST(category, "name", {
			new AST(token, "\"" + funcName + "\"")
			  })})}),
	    new AST(token, ")")
	    })
    };
  std::list<AST*> directiveList = {
    new AST(token, "  "),
    new AST(category, "expr", {
	new AST (category, "call", {
	    new AST(category, "name", {
	      new AST(category, "name", {
		  new AST(token, profileObjectName)
		    }),
		new AST(token, "."),
		new AST(category, "name", {
		    new AST(token, "count")
		      })
		}),
	      new AST(category, "argument_list", 
		      argList
		      )})}),
    new AST(token, semiOrComma)
  };
  child.insert(itr, new AST(category, "expr_stmt", directiveList));
}


void AST::iterateToBefore(std::list<AST*>::iterator &itr, std::string elName) { 
  while ((itr != child.end()) && ((*itr)->tag != elName)) { 
    //    std::cout << (*itr)->tag << std::endl;
    ++itr;
    //std::cout << "itr++" << std::endl;
  }
  //std::cout << "out of loop" << std::endl;  
} 

/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node
        else
            (*i)->print(out);    //Category node
    }
    return out;
}

    

/////////////////////////////////////////////////////////////////////
// Utilities
//


/////////////////////////////////////////////////////////////////////
// This returns true if a syntactic category is encountered that
//  will not be profiled.
//
// This is IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}


/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}


/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}

