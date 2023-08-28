// arrow functions are used for passing this value from its lexical parent

const person ={
    Name: "Subayyal",
    Place:"Lahore",
   GRABDETAIL: function(){
        console.log(this.Name);


        setTimeout( function(){
        console.log(this.Person);
        })

        setTimeout( ()=>
        console.log(this.Person) )

    }
};

person. GRABDETAIL();