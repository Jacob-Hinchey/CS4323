//Name: Jacob Hinchey
//EMail: jacob.hinchey@okstate.edu
//Date: 4/10/2020
//This program is made to represt four different routers using arrays of ints.
//Each buffer of the router is equal to a single packet.
//Each full buffer is represented by a 1, and empty is represented by 0.
//The initial router configeration used can be changed by adjusting the
//routA, routB, routC,and routD int arrays.
//The idea for handling deadlock was based mostly on banker's algorithm.
//This checks the availablity of the resources nessacary before trying to move the packets.
//This program handles deadlock by terminating the current process.




#include <stdio.h>
#include <string.h>
#include <unistd.h>
//struct router{
//    int used;
//};

int main(){
//    struct router a;
//    struct router b;
//    struct router c;
//    struct router d;
    int count;
    count = 0;
    
    //This is the starting martix. edit this to try different senarios
    //1 = filled and 0 = empty
    int routA[8] = { 1, 1, 1 ,0 ,0 ,1 ,0 ,0 };
    int routB[8] = { 1, 0, 0 ,1 ,0 ,0 ,1 ,0 };
    int routC[8] = { 1, 1, 1 ,0 ,0 ,1 ,0 ,1 };
    int routD[8] = { 0, 1, 1 ,1 ,1 ,0 ,0 ,0 };
    
    int max[8] = {1,1,1,1,1,1,1,1};
    
    int flag = 0;
    while(flag == 0){
        //prints the current routers based on whether they are filled or not
        printf("\nCurrent router buffers:\nA: ");
        for(int i = 0; i < 8; i++)
           printf("%d ", routA[i]);
        printf("\nB: ");
        for(int i = 0; i < 8; i++)
           printf("%d ", routB[i]);
        printf("\nC: ");
        for(int i = 0; i < 8; i++)
           printf("%d ", routC[i]);
        printf("\nD: ");
        for(int i = 0; i < 8; i++)
           printf("%d ", routD[i]);
        printf("\n");
        
        //gets user's input on what action to preform
        char user_choice[10] = "";
        printf("\nType the number of your preferred option\n1.Add packets in a buffer\n2.Move packets\n3.Remove all items from routers\n4.Quit\n");
        scanf("%s", user_choice);
        
        
        //If the user wants to add packets into a router
        if(strcmp(user_choice,"1") == 0){
            while(1){
                    //gets the number of packets to be added and assigns an int value
                   char pack_add[10] = "";
                   printf("\nHow many packets would you like to add(1 to 8) or q to exit\nIf it is more than avaliable the router will be filled to the max 8 buffers\n");
                   scanf("%s",pack_add);
                   int packs = 0;
                   if(strcmp(pack_add,"1") ==0){
                       packs = 1;
                   }
                   else if(strcmp(pack_add,"2") ==0){
                       packs = 2;
                   }
                   else if(strcmp(pack_add,"3") ==0){
                       packs = 3;
                   }
                   else if(strcmp(pack_add,"4") ==0){
                       packs = 4;
                   }
                   else if(strcmp(pack_add,"5") ==0){
                       packs = 5;
                   }
                   else if(strcmp(pack_add,"6") ==0){
                       packs = 6;
                   }
                   else if(strcmp(pack_add,"7") ==0){
                       packs = 7;
                   }
                   else if(strcmp(pack_add,"8") ==0){
                       packs = 8;
                   }
                   else if(strcmp(pack_add,"Q") == 0 || strcmp(pack_add,"q") == 0){
                       break;
                   }
                   else{
                       printf("\nNot a valid input\n");
                       continue;
                   }
                //gets user's preferred router
                char router_choice[10] = "";
                printf("\nPick the router(A,B,C,D) or q to exit:\n");
                scanf("%s", router_choice);
                count = 0;
                //for a add the new packets
                if(strcmp(router_choice,"A") == 0 || strcmp(router_choice,"a") == 0){
                    for(int i = 0; i < 8; i++){
                        if(routA[i] == 1){
                            continue;
                        }
                        else{
                            routA[i] = 1;
                            packs--;
                        }
                        if(packs == 0){
                            break;
                        }
                    }
                }
                
                //for b add the new packets
                else if(strcmp(router_choice,"B") == 0 || strcmp(router_choice,"b") == 0){
                    for(int i = 0; i < 8; i++){
                        if(routB[i] == 1){
                            continue;
                        }
                        else{
                            routB[i] = 1;
                            packs--;
                        }
                        if(packs == 0){
                            break;
                        }
                    }
                }
                
                //for c add the new packets
                else if(strcmp(router_choice,"C") == 0 || strcmp(router_choice,"c") == 0){
                    for(int i = 0; i < 8; i++){
                        if(routC[i] == 1){
                            continue;
                        }
                        else{
                            routC[i] = 1;
                            packs--;
                        }
                        if(packs == 0){
                            break;
                        }
                    }
                }
                
                //for d add the new packets
                else if(strcmp(router_choice,"D") == 0 || strcmp(router_choice,"d") == 0){
                    for(int i = 0; i < 8; i++){
                        if(routD[i] == 1){
                            continue;
                        }
                        else{
                            routD[i] = 1;
                            packs--;
                        }
                        if(packs == 0){
                            break;
                        }
                    }
                }
                else if(strcmp(router_choice,"Q") == 0 || strcmp(router_choice,"q") == 0){
                    break;
                }
                else{
                    printf("\nNot a valid input\n");
                }
            }
            continue;
        }
        
        //if the user wants to move packets to test deadlock
        //deadlock is handled by stopping the process exicution
        else if(strcmp(user_choice,"2")== 0){
            while(1){
                //number of packets to be moved and assigns them to ints
                char package_amount[10] = "";
                printf("\nHow many packets would you like to move(1 to 8) or q to exit\n");
                scanf("%s", package_amount);
                int pack = 0;
                if(strcmp(package_amount,"1") ==0){
                    pack = 1;
                }
                else if(strcmp(package_amount,"2") ==0){
                    pack = 2;
                }
                else if(strcmp(package_amount,"3") ==0){
                    pack = 3;
                }
                else if(strcmp(package_amount,"4") ==0){
                    pack = 4;
                }
                else if(strcmp(package_amount,"5") ==0){
                    pack = 5;
                }
                else if(strcmp(package_amount,"6") ==0){
                    pack = 6;
                }
                else if(strcmp(package_amount,"7") ==0){
                    pack = 7;
                }
                else if(strcmp(package_amount,"8") ==0){
                    pack = 8;
                }
                else if(strcmp(package_amount,"Q") == 0 || strcmp(package_amount,"q") == 0){
                    break;
                }
                else{
                    printf("\nNot a valid input\n");
                    continue;
                }
                int num = pack;
                char router_choice[10] = "";
                char move_choice[10] = "";
                
                //gets where to take the packets from
                printf("\nPick the router(A,B,C,D) that you would like to move packages from\n If the router you pick does not have enough packets, more will be added.\n");
                scanf("%s", router_choice);
                //gets where to move the packets to
                printf("\nPick the router(A,B,C,D) that you would like to move packages to or q to exit:\n");
                scanf("%s", move_choice);
                
                //manages senarios for a
                if(strcmp(router_choice,"A") == 0 || strcmp(router_choice,"a") == 0){
                    
                    //checks to make sure resources are available for each movement
                    //then tells the user if the process succeeded
                    
                        if(strcmp(move_choice,"A") == 0 || strcmp(move_choice,"a") == 0){
                            printf("\nMovement from A -> A results in no deadlocks, because no movement was made.\n");
                        }
                        else if(strcmp(move_choice,"B") == 0 || strcmp(move_choice,"b") == 0){
                            printf("\nChecking buffer space in B\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routB[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nB had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routB[i]==1){
                                        continue;
                                    }
                                    else{
                                        routB[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routA[j] == 1){
                                               routA[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from A -> B\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nB had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"C") == 0 || strcmp(move_choice,"c") == 0){
                            printf("\nChecking buffer space in B\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routB[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("B had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated",amt);
                                break;
                            }
                            printf("\nB had enough buffer space.\n");
                            printf("\nChecking buffer space in C\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routC[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nC had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routC[i]==1){
                                        continue;
                                    }
                                    else{
                                        routC[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routA[j] == 1){
                                               routA[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from A -> C\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nC had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                            
                        }
                        else if(strcmp(move_choice,"D") == 0 || strcmp(move_choice,"d") == 0){
                            printf("\nChecking buffer space in B\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routB[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nB had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nB had enough buffer space.\n");
                            printf("\nChecking buffer space in C\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routC[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nC had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nC had enough buffer space.\n");
                            printf("\nChecking buffer space in D\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routD[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nD had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routD[i]==1){
                                        continue;
                                    }
                                    else{
                                        routD[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routA[j] == 1){
                                               routA[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from A -> D\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nD had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"Q") == 0 || strcmp(move_choice,"q") == 0){
                            break;
                        }
                    
                }
                
                //if they want to move packets from b
                else if(strcmp(router_choice,"B") == 0 || strcmp(router_choice,"b") == 0){
                    
//                    checks to make sure resources are available for each movement
//                    then tells the user if the process succeeded
                        if(strcmp(move_choice,"A") == 0 || strcmp(move_choice,"a") == 0){
                            printf("\nChecking buffer space in C\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routC[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nC had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nC had enough buffer space.\n");
                            printf("\nChecking buffer space in D\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routD[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nD had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nD had enough buffer space.\n");
                            printf("\nChecking buffer space in A\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routA[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nA had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routA[i]==1){
                                        continue;
                                    }
                                    else{
                                        routA[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routB[j] == 1){
                                               routB[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from B -> A\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nA had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"B") == 0 || strcmp(move_choice,"b") == 0){
                            printf("\nMovement from B -> B results in no deadlocks, because no packages were moved.\n");
                        }
                        else if(strcmp(move_choice,"C") == 0 || strcmp(move_choice,"c") == 0){
                            printf("\nChecking buffer space in C\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routC[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nC had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routC[i]==1){
                                        continue;
                                    }
                                    else{
                                        routC[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routB[j] == 1){
                                               routB[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from B -> C\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nC had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"D") == 0 || strcmp(move_choice,"d") == 0){
                            printf("\nChecking buffer space in C\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routC[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nC had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nC had enough buffer space.\n");
                            printf("\nChecking buffer space in D\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routD[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nD had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routD[i]==1){
                                        continue;
                                    }
                                    else{
                                        routD[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routB[j] == 1){
                                               routB[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from B -> D\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nD had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                            
                        }
                        else if(strcmp(move_choice,"Q") == 0 || strcmp(move_choice,"q") == 0){
                            break;
                        }
                    
                }
                
                //manages senarios for c
                else if(strcmp(router_choice,"C") == 0 || strcmp(router_choice,"c") == 0){
                    
                    //checks to make sure resources are available for each movement
                    //then tells the user if the process succeeded
                        if(strcmp(move_choice,"A") == 0 || strcmp(move_choice,"a") == 0){
                            printf("\nChecking buffer space in D\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routD[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nD had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nD had enough buffer space.\n");
                            printf("\nChecking buffer space in A\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routA[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nA had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routA[i]==1){
                                        continue;
                                    }
                                    else{
                                        routA[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routC[j] == 1){
                                               routC[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from C -> A\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nA had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"B") == 0 || strcmp(move_choice,"b") == 0){
                            printf("\nChecking buffer space in D\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routD[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nD had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nD had enough buffer space.\n");
                            printf("\nChecking buffer space in A\n");
                            sleep(2);
                            
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routA[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nA had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nA had enough buffer space.\n");
                            printf("\nChecking buffer space in B\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routB[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nB had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routB[i]==1){
                                        continue;
                                    }
                                    else{
                                        routB[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routC[j] == 1){
                                               routC[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from C -> B\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nB had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"C") == 0 || strcmp(move_choice,"c") == 0){
                            printf("\nMovement from C -> C results in no deadlocks, because no packages were moved.\n");
                        }
                        else if(strcmp(move_choice,"D") == 0 || strcmp(move_choice,"d") == 0){
                            printf("\nChecking buffer space in D\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routD[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nD had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routD[i]==1){
                                        continue;
                                    }
                                    else{
                                        routD[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routC[j] == 1){
                                               routC[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from C -> D\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nD had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(user_choice,"Q") == 0 || strcmp(user_choice,"q") == 0){
                            break;
                        }
                    
                }
                
                //manages senarios for d
                else if(strcmp(router_choice,"D") == 0 || strcmp(router_choice,"d") == 0){
                    
                    //checks to make sure resources are available for each movement
                    //then tells the user if the process succeeded
                    
                        if(strcmp(move_choice,"A") == 0 || strcmp(move_choice,"a") == 0){
                            printf("\nChecking buffer space in A\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routA[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nA had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routA[i]==1){
                                        continue;
                                    }
                                    else{
                                        routA[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routD[j] == 1){
                                               routD[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from D -> A\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nA had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"B") == 0 || strcmp(move_choice,"b") == 0){
                           printf("\nChecking buffer space in A\n");
                           sleep(2);
                           count = 0;
                           for(int i =0; i<8;i++){
                               if(routA[i]==0){
                                   count++;
                               }
                           }
                           if(count < pack){
                               int amt = pack-count;
                               printf("\nA had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                               break;
                           }
                           printf("\nA had enough buffer space.\n");
                           printf("\nChecking buffer space in B\n");
                           sleep(2);
                           count = 0;
                           for(int i =0; i<8;i++){
                               if(routB[i]==0){
                                   count++;
                               }
                           }
                           if(count >= pack){
                               printf("\nB had enough buffer space.\n");
                               for(int i =0; i<8;i++){
                                   if(routB[i]==1){
                                       continue;
                                   }
                                   else{
                                       routB[i]=1;
                                       pack--;
                                   }
                                   if(pack == 0){
                                       for(int j = 0; j<8;j++){
                                          if(routD[j] == 1){
                                              routD[j] = 0;
                                              num--;
                                          }
                                          if(num == 0){
                                              break;
                                          }
                                       }
                                       printf("\nItems successfully moved from D -> B\n");
                                       break;
                                   }
                               }
                           }
                           else{
                               int amt = pack-count;
                               printf("\nB had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                           }
                        }
                    
                        else if(strcmp(move_choice,"C") == 0 || strcmp(move_choice,"c") == 0){
                            
                            printf("\nChecking buffer space in A\n");
                            sleep(2);count = 0;
                            for(int i =0; i<8;i++){
                                if(routA[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nA had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nA had enough buffer space.\n");
                            printf("\nChecking buffer space in B\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routB[i]==0){
                                    count++;
                                }
                            }
                            if(count < pack){
                                int amt = pack-count;
                                printf("\nB had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                                break;
                            }
                            printf("\nB had enough buffer space.\n");
                            printf("\nChecking buffer space in C\n");
                            sleep(2);
                            count = 0;
                            for(int i =0; i<8;i++){
                                if(routC[i]==0){
                                    count++;
                                }
                            }
                            if(count >= pack){
                                printf("\nC had enough buffer space.\n");
                                for(int i =0; i<8;i++){
                                    if(routC[i]==1){
                                        continue;
                                    }
                                    else{
                                        routC[i]=1;
                                        pack--;
                                    }
                                    if(pack == 0){
                                        for(int j = 0; j<8;j++){
                                           if(routD[j] == 1){
                                               routD[j] = 0;
                                               num--;
                                           }
                                           if(num == 0){
                                               break;
                                           }
                                        }
                                        printf("\nItems successfully moved from D -> C\n");
                                        break;
                                    }
                                }
                            }
                            else{
                                int amt = pack-count;
                                printf("\nC had %d less reasources than necassary.\nThis results in deadlock. Opperation terminated\n",amt);
                            }
                        }
                        else if(strcmp(move_choice,"D") == 0 || strcmp(move_choice,"d") == 0){
                            printf("\nMovement from D -> D results in no deadlocks, because no packages were moved.\n");
                        }
                        else if(strcmp(move_choice,"Q") == 0 || strcmp(move_choice,"q") == 0){
                            break;
                        }
                    
                }
                else if(strcmp(user_choice,"Q") == 0 || strcmp(user_choice,"q") == 0){
                    break;
                }
                else{
                    printf("\nNot a valid input\n");
                    continue;
                }
            }
            continue;
        }
        
        //empties the routers
        else if(strcmp(user_choice,"3") == 0){
            for(int i = 0;i<8;i++){
                routA[i]=0;
                routB[i]=0;
                routC[i]=0;
                routD[i]=0;
            }
        }
        else if(strcmp(user_choice,"4") == 0){
            break;
        }
        else{
            printf("\nNot a valid input\n");
        }

    }
    return 0;
}
