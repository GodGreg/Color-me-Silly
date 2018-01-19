package com.gregmaxin.colourmesilly;

import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.GridLayout;
import android.widget.EditText;
import android.widget.TextView;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.graphics.Color;


public class MainActivity extends AppCompatActivity {
    String name = "";
    String layout = "Menu";
    /** -------------------------------------------------------------------------------------------
    Native Method Declarations
     ------------------------------------------------------------------------------------------- **/
    public native String stringFromJNI(int cmd,int x,int y,int z);


    /** -------------------------------------------------------------------------------------------
     Load Libraries
     ------------------------------------------------------------------------------------------- **/
    static {
        System.loadLibrary("native-lib");
        //System.loadLibrary("Test");
        //System.loadLibrary("Grid.cpp");
        //System.loadLibrary("Cell.cpp");
       // System.loadLibrary("Observer.cpp");
       // System.loadLibrary("Move.cpp");

    }

    /** -------------------------------------------------------------------------------------------
     This is run when the game starts
     ------------------------------------------------------------------------------------------- **/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.out.print("Game Created");
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
    }

    /** -------------------------------------------------------------------------------------------
     Gregs Graphical methods
     ------------------------------------------------------------------------------------------- **/
    public void OnClick(View view) {
        EditText editText = findViewById(R.id.Name);

        if (layout == "Game") {
            GridLayout grid = findViewById(R.id.gridLayout);
            int numx = grid.getRowCount();
            int numy = grid.getColumnCount();
            for (int x = 0; x < numx; x++) {
                for (int y = 0; y < numy; y++){
                    Button button = findViewById(getResources().getIdentifier("button" + x + "" + y, "id", this.getPackageName()));

                    if (button != null && button.getId() == view.getId()) {
                        Log.v("myTag", "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
                        String Display = stringFromJNI(2, x, y, 1);
                        UpdateBoard(Display);
                        TextView title2 = findViewById(R.id.Score);
                        title2.setText("1");
                    }
                }
            }
        }
        else if (layout == "Menu") {
            switch (view.getId()) {
                case R.id.Play:
                    name = editText.getText().toString();
                    setContentView(R.layout.game);
                    layout = "Game";
                    TextView title = findViewById(R.id.Score);
                    String init = stringFromJNI(1, 0, 0, 0);
                    title.setText("0");
                    UpdateBoard(init);
                    break;
                case R.id.Name:
                    editText.getText().clear();
                default:
                    Log.v("myTag", "This is my message");
            }
        }
    }
    public void UpdateBoard(String s){
        GridLayout grid = findViewById(R.id.gridLayout);
        int numx = grid.getRowCount();
        int numy = grid.getColumnCount();
        char[] arr = s.toCharArray();
        int n = 0;
        for (int x = 0; x < numx; x++) {
            for (int y = 0; y < numy; y++) {
                Button button = findViewById(getResources().getIdentifier("button" + x + "" + y, "id", this.getPackageName()));
                if (arr[n] == 'G')
                    button.setBackgroundColor(Color.GREEN);
                if (arr[n] == 'R')
                    button.setBackgroundColor(Color.RED);
                n++;
            }
        }
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

}
