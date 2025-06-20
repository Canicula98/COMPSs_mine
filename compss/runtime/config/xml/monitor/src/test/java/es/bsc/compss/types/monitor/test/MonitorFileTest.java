/*
 *  Copyright 2002-2025 Barcelona Supercomputing Center (www.bsc.es)
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */
package es.bsc.compss.types.monitor.test;

import static org.junit.Assert.assertNotNull;

import es.bsc.compss.types.monitor.jaxb.COMPSsStateType;
import es.bsc.compss.types.monitor.jaxb.ObjectFactory;

import java.io.File;
import java.io.StringWriter;
import java.net.URISyntaxException;

import jakarta.xml.bind.JAXBContext;
import jakarta.xml.bind.JAXBElement;
import jakarta.xml.bind.JAXBException;
import jakarta.xml.bind.Marshaller;
import jakarta.xml.bind.Unmarshaller;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.junit.AfterClass;
import org.junit.BeforeClass;
import org.junit.Test;


public class MonitorFileTest {

    // Test Logger
    private static final Logger LOGGER = LogManager.getLogger("Console");


    @BeforeClass
    public static void beforeClass() throws Exception {
        /*
         * if (TMP_FILE.exists()){ TMP_FILE.delete(); }
         */
    }

    @Test
    public void checkMonitorValuesTest() throws URISyntaxException, JAXBException {
        File f = new File(MonitorFileTest.class.getResource("/monitor.xml").toURI());
        JAXBContext jbc = JAXBContext.newInstance(ObjectFactory.class.getPackage().getName());
        Unmarshaller um = jbc.createUnmarshaller();
        JAXBElement<?> element = (JAXBElement<?>) um.unmarshal(f);
        COMPSsStateType monitor = (COMPSsStateType) element.getValue();

        assertNotNull(monitor);
        assertNotNull(monitor.getTasksInfo());
        assertNotNull(monitor.getTasksInfo().getApplication());
        assertNotNull(monitor.getCoresInfo());
        assertNotNull(monitor.getCoresInfo().getCore());
        assertNotNull(monitor.getResourceInfo());
        assertNotNull(monitor.getResourceInfo().getResource());

        jbc = JAXBContext.newInstance(COMPSsStateType.class);
        Marshaller m = jbc.createMarshaller();
        m.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
        ObjectFactory objFact = new ObjectFactory();
        StringWriter writer = new StringWriter();
        m.marshal(objFact.createCOMPSsState(monitor), writer);
        LOGGER.info("\nPRINTING MARSHALLED MONITOR:\n");
        LOGGER.info(writer.toString() + "\n");
    }

    @AfterClass
    public static void afterClass() throws Exception {
        /*
         * if (TMP_FILE.exists()){ TMP_FILE.delete(); }
         */
    }

}
