

let person = {
    Name: 'Subayyal Saeed',
    Nationality: 'Pakistani',
   GetNationality(){
        console.log("The Name of Person is "+this.Name+" and he is a : "+this.Nationality+" of Province: "+country.Province);
    }
};

let country ={
    Province: 'Lahore'
};
person.GetNationality();