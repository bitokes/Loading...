(function() {
    
    var config = {

            apiKey: "AIzaSyCQ3e3-zIuf2KT_Yl_D3bR46qaiu_hAxcg",
            authDomain: "pap2020-8183b.firebaseapp.com",
            databaseURL: "https://pap2020-8183b.firebaseio.com",
            projectId: "pap2020-8183b",
            storageBucket: "pap2020-8183b.appspot.com",
            messagingSenderId: "45567050567",
            appId: "1:45567050567:web:8d442ed63f1e459b810262",
            measurementId: "G-7M641EE6W9"
    };

    firebase.initializeApp(config);

    var database = firebase.database();

    const tempElement = document.getElementById('temperature');
    const humElement = document.getElementById('humidity');
    const movimentoElement = document.getElementById('Movimento');

   
    const tempRef = database.ref('dht11').child('temperature');

    const humRef = database.ref('dht11').child('humidity');

    const movimentoRef = database.ref('movimento');

    
    tempRef.limitToLast(1).on('value', function(snapshot) {
        snapshot.forEach(function(childSnapshot) {
            var childData = childSnapshot.val();
            console.log("temperature: " + childData);
            tempElement.innerText = childData;
        });
    });

    humRef.limitToLast(1).on('value', function(snapshot) {
        snapshot.forEach(function(childSnapshot) {
            var childData = childSnapshot.val();
            console.log("humidity: " + childData);
            humElement.innerText = childData;
        });
    });

    movimentoRef.limitToLast(1).on('value', function(snapshot) {
        snapshot.forEach(function(childSnapshot) {
            var childData = childSnapshot.val();
            console.log("movimento: " + childData); 
            
           
           if (childData == 1){
            movimentoElement.innerText = "movimento detetado!!";
           }
           else if(childData == 0){
            movimentoElement.innerText = "nenhum movimento detetado";
           };
           
        });
    });


    lon1.addEventListener('click', () =>{

            firebase.database().ref('rele1').set('on');
           

    } )

    loff1.addEventListener('click', () =>{

        firebase.database().ref('rele1').set('off');
        
    } )

    lon2.addEventListener('click', () =>{

        firebase.database().ref('rele2').set('on');
       

} )

loff2.addEventListener('click', () =>{

    firebase.database().ref('rele2').set('off');
    
} )

lon3.addEventListener('click', () =>{

    firebase.database().ref('rele3').set('on');
   

} )

loff3.addEventListener('click', () =>{

firebase.database().ref('rele3').set('off');

} )

lon4.addEventListener('click', () =>{

    firebase.database().ref('rele4').set('on');
   

} )

loff4.addEventListener('click', () =>{

firebase.database().ref('rele4').set('off');

} )


}());
