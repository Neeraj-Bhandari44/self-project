//Image Encryption and Decryption
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.FlowLayout;
import java.awt.Font;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
//SWing is used for making java GUI(graphical user interface)
public class ImageOperation {
     static int j=0,a=-1;
    public static void operate(int key)
    {
        JFileChooser fileChooser=new JFileChooser();
        fileChooser.showOpenDialog(null);
        File file=fileChooser.getSelectedFile();
        //file FileInputStream class object
        try
        {
            FileInputStream fis=new FileInputStream(file);
            byte []data=new byte[fis.available()];
            fis.read(data);
            int i=0;
            for(byte b:data)
            {
                System.out.println(b);
                data[i]=(byte)(b^key);
                i++;
            }
            FileOutputStream fos=new FileOutputStream(file);
            fos.write(data);
            fos.close();
            fis.close();
            if(j%2==0){
            JOptionPane.showMessageDialog(null, "Encrypted successfully!!!");
            j++;
            }
            else{
                JOptionPane.showMessageDialog(null, "Decrypted successfully!!!"); 
                j++;
            }
        }catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) {
        
        System.out.println("this is testing");

        JFrame f=new JFrame();
        f.setTitle("Image Encription and Decryption");
        f.setSize(350,400 );
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Font font=new Font("TimesRoman",Font.BOLD|Font.ITALIC,30);
        //creating button
        JButton button=new JButton();
        button.setText("Insert Image");
        button.setFont(font);

        //creating text field 

        JTextField textField=new JTextField(10);
        textField.setFont(font);

        
        button.addActionListener(e->{                  //lamda function
            System.out.println("Process started");
            String text=textField.getText();
            int temp=Integer.parseInt(text);
            if(a==-1){
            a=temp;
            }
            if(a==temp){
            operate(temp);
            }
            else{
                JOptionPane.showMessageDialog(null, "Key you have entered is invalid"); 
            }
        });

        f.setLayout(new FlowLayout());

        f.add(button);
        f.add(textField);
        f.setVisible(true);

    }
}