package com.example.fancontroll;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;

import com.utils.StreamTool;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import android.app.Activity;

public class MainActivity extends Activity {
	
	private EditText username;
	
	private EditText password;
	
	private Button loginBtn;
	
	private final static String PATH = "http://localhost:8080/user/";
	
	private String wholeUrl;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.login);
        
        username = (EditText) findViewById(R.id.username);
        password = (EditText) findViewById(R.id.password);
        loginBtn = (Button) findViewById(R.id.login);
        
        loginBtn.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				loginByUsername();
			}
		});
    }
    
    private void loginByUsername(){
    	
    	//获取登录信息
    	final String user = username.getText().toString().trim();
    	String pwd = password.getText().toString().trim();
    	
    	//判断是否为空
    	if (TextUtils.isEmpty(user) || TextUtils.isEmpty(pwd)) {
			Toast.makeText(MainActivity.this, "请输入账号和密码", Toast.LENGTH_SHORT).show();
			return;
		}
    	
    	//向服务器提交数据进行验证
    	new Thread(){
    		public void run() {
    			
    			//连接网络
    	    	try {
    	    		//url编码传输
        			wholeUrl = PATH + URLEncoder.encode(user, "UTF-8");
    				URL url = new URL(wholeUrl);
    				
    				//建立一个连接---Connection对象
    				HttpURLConnection conn = (HttpURLConnection) url.openConnection();
    				
    				//设置请求方式
    				conn.setRequestMethod("GET");
    				conn.setConnectTimeout(5000);
    				
    				//获得服务器返回的状态码，根据状态码判断访问是否成功
    				int code = conn.getResponseCode();
    				if (code == 200) { //成功处理请求
    					
    					InputStream in = conn.getInputStream();
    					
    					//将字符流转为字符串
    					String data = StreamTool.decodeStream(in);
    					
    					System.out.println(data);
    					
    					//解析服务端回送的json格式的数据
    					//返回对象T
    				}
    				
    			} catch (Exception e) {
    				
    				e.printStackTrace();
    			}
    		};
    	}.start();
    }
}
