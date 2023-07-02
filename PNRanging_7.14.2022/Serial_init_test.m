%Run these commands before running the program.
%These commands only need to be entered once, as such they are commented
%out for testing purposes.
%=================================================%
%init_serial = serial('COM1','BaudRate',500000);
%fopen(init_serial);



%==========================================================================
%                                 Main Body
%==========================================================================

b = 10:100400; %Bit rate per second - tranmission limitations
f = 1:100:500e6; %Code rate, bits per second
bd = 1./f; %Bit duration in seconds
c = 3*10e8; %Speed of light in m/s
i = 2; %Used for incrementing the code length


while i < 5
   
    %Number of code segments used
    C = i;
   
    %Call the function that duplicates code sequences to add the arrays
    %togeher correctly and create the composite code
    [code_length, composite_signal] = component_sequence_extention(C);
   
   
    %Incremeneting index
    i = i + 1;
   
end

i = 1;

while i < length(composite_signal)+1
    if composite_signal(i) == -1
        composite_signal(i) = 0;
    end
    i = i + 1;
end



composite_signal = cat(2,composite_signal,[0,0]); %this concatenates incorrectly, fix this later
csp_header_temp = [0 1 0 1 1 0 0 0 0 0 0 1 0 0 1 0 0 1 1 0 1 0 1 ...
    0 0 0 0 0 0 0 0 0];
csp_header_temp = num2str(csp_header_temp')';
csp_header =  zeros(1,4);

i = 1;
n = 8;
k = 1;
while n < length(csp_header_temp)+1
    csp_header(1,k) = bin2dec(csp_header_temp(i:n));
    i = i + 8;
    n = n + 8;
    k = k + 1;
end

data_temp = num2str(composite_signal')';
data = zeros(1,289);
i = 1;
n = 8;
k = 1;

while i < length(data_temp)+1
    data(1,k) = bin2dec(data_temp(i:n));
    i = i + 8;
    n = n + 8;
    k = k + 1;

end
data = uint8(data);

fwrite(init_serial,data);




%==========================================================================
%                Function Used for Creating Composite Code
%==========================================================================
 
 function [code_length, composite_signal] = component_sequence_extention(C)
   
 %component sequences
 C1 = [1, -1];
 C2 = [1, 1, 1, -1, -1, 1, -1];
 C3 = [1, 1, 1, -1, -1, -1, 1, -1, 1, 1, -1];
 C4 = [1, 1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 1 -1];
 C5 = [1, 1, 1, 1,-1, 1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, -1];
 C6 =  [1, 1, 1, 1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, ...
     -1, -1, -1, -1];
 
 %used for indexing
 i = 1;
 
 %Finds the selected component sequence
 switch C
%=========================================================================
% Case C1
%=========================================================================
     
     case 1

         
%=========================================================================
% Case C2
%=========================================================================    
     
     case 2
         %Find the total length of the code sequence
         code_length = length(C1)*length(C2);
         
         %Finds how many times to repeat for each component
         C1_repeat = ceil(code_length/length(C1));
         C2_repeat = ceil(code_length/length(C2));
         
         %repeats matrix by the ceiling values
         C1 = repmat(C1,1,C1_repeat);
         C2 = repmat(C2,1,C2_repeat);
         
         %preallocating array for optimization
         composite_signal = zeros(1,code_length);
         
         %creating the entire length of the composite signal
         while i < code_length + 1
             composite_signal(i) = sign((4*C1(i))+C2(i));
             i = i + 1;
         end
%=========================================================================
% Case C3
%=========================================================================
     
     case 3
           
         %Find the total length of the code sequence
         code_length = length(C1)*length(C2)*length(C3);
         
         %Finds how many times to repeat for each component
         C1_repeat = ceil(code_length/length(C1));
         C2_repeat = ceil(code_length/length(C2));
         C3_repeat = ceil(code_length/length(C3));
         
         %repeats matrix by the ceiling values
         C1 = repmat(C1,1,C1_repeat);
         C2 = repmat(C2,1,C2_repeat);
         C3 = repmat(C3,1,C3_repeat);
         
         %preallocating array for optimization
         composite_signal = zeros(1,code_length);
         
         %creating the entire length of the composite signal
         while i < code_length + 1
             composite_signal(i) = sign((4*C1(i))+C2(i)-C3(i));
             i = i + 1;
         end
%=========================================================================
% Case C4
%=========================================================================
     
     case 4
         %Find the total length of the code sequence
         code_length = length(C1)*length(C2)*length(C3)*length(C4);
         
         %Finds how many times to repeat for each component
         C1_repeat = ceil(code_length/length(C1));
         C2_repeat = ceil(code_length/length(C2));
         C3_repeat = ceil(code_length/length(C3));
         C4_repeat = ceil(code_length/length(C4));
         
         %repeats matrix by the ceiling values
         C1 = repmat(C1,1,C1_repeat);
         C2 = repmat(C2,1,C2_repeat);
         C3 = repmat(C3,1,C3_repeat);
         C4 = repmat(C4,1,C4_repeat);
         
         %preallocating array for optimization
         composite_signal = zeros(1,code_length);
         
         %creating the entire length of the composite signal
         while i < code_length + 1
             composite_signal(i) = sign((2*C1(i))+C2(i)-C3(i)-C4(i));
             i = i + 1;
         end
         
%=========================================================================
% Case C5
%=========================================================================  
     case 5
         %Find the total length of the code sequence
         code_length = length(C1)*length(C2)*length(C3)*...
             length(C4)*length(C5);
         
         %Finds how many times to repeat for each component
         C1_repeat = ceil(code_length/length(C1));
         C2_repeat = ceil(code_length/length(C2));
         C3_repeat = ceil(code_length/length(C3));
         C4_repeat = ceil(code_length/length(C4));
         C5_repeat = ceil(code_length/length(C5));
         
         %repeats matrix by the ceiling values
         C1 = repmat(C1,1,C1_repeat);
         C2 = repmat(C2,1,C2_repeat);
         C3 = repmat(C3,1,C3_repeat);
         C4 = repmat(C4,1,C4_repeat);
         C5 = repmat(C5,1,C5_repeat);

         
         %preallocating array for optimization
         composite_signal = zeros(1,code_length);
         
         %creating the entire length of the composite signal
         while i < code_length + 1
             composite_signal(i) = sign((4*C1(i))+C2(i)-C3(i)-C4(i)+C5(i));
             i = i + 1;
         end
           

%=========================================================================
% Case C6
%=========================================================================
     case 6
         
         %Find the total length of the code sequence
         code_length = length(C1)*length(C2)*length(C3)*length(C4)*...
             length(C5)*length(C6);
         
         %Finds how many times to repeat for each component
         C1_repeat = ceil(code_length/length(C1));
         C2_repeat = ceil(code_length/length(C2));
         C3_repeat = ceil(code_length/length(C3));
         C4_repeat = ceil(code_length/length(C4));
         C5_repeat = ceil(code_length/length(C5));
         C6_repeat = ceil(code_length/length(C6));
         
         %repeats matrix by the ceiling values
         C1 = repmat(C1,1,C1_repeat);
         C2 = repmat(C2,1,C2_repeat);
         C3 = repmat(C3,1,C3_repeat);
         C4 = repmat(C4,1,C4_repeat);
         C5 = repmat(C5,1,C5_repeat);
         C6 = repmat(C6,1,C6_repeat);

         
         %preallocating array for optimization
         composite_signal = zeros(1,code_length);
         
         %creating the entire length of the composite signal
         while i < code_length + 1
             composite_signal(i) = sign((4*C1(i))+C2(i)-C3(i)-C4(i)...
                 +C5(i)- C6(i));
             i = i + 1;
         end
           
           
%=========================================================================
% Case for a value that is outside 1-6
%=========================================================================

        otherwise  
           
 end
 end


function CRC = crc(data)
    %Input should be MSB.......LSB,Big Endian
    %The output from the CSP packet should already be in Big endian
    %The receieved data from CSP is LSB...MSB
    %Which means you have to do a byte swap from LSB...MSB to MSB...LSB
    % poly2 = [32 28 27 26 25 23 22 20 19 18 14 13 11 10 9 8 7 6 0];
    %The polynomial is CRC32-C or the Castigoli polynomial 0x1EDC6F41
    poly = 'z^32 + z^28 + z^27 + z^26 + z^25 + z^23 + z^22 + z^20 + z^19 + z^18 + z^14 +z^13 + z^11 + z^10 + z^9 + z^8 + z^6 + 1';  %Generator polynomial
    %poly3 = [1 0 0 0 1 1 1 1 0 1 1 0 1 1 1 0 0 0 1 1 0 1 1 1 1 0 1 0 0 0 0 0 1];
    data = double(data);
    hgen = comm.CRCGenerator('Polynomial',poly,...
        'InitialConditions',1,...
        'DirectMethod',true,...
        'ReflectInputBytes',true,...
        'ReflectChecksums',true,...    
        'FinalXOR',1);
    whoa1 = hgen(data);
    %whoa2 = whoa1(end-31:end)';
    CRC = whoa1;
end
	
